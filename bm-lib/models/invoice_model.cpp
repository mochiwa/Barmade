#include "invoice_model.h"
using namespace std;
InvoiceModel::InvoiceModel(QObject *parent):
    AbstractListModel(parent)
{
    //initEntities();
}

void InvoiceModel::setStakeholder(int id)
{
    beginResetModel();
    stakeholder = id;
    loadOrderFrom(stakeholder);
    endResetModel();
}

void InvoiceModel::initEntities()
{
    unique_ptr<vector<unique_ptr<Invoice>>> orders=db.orderDao->getAll();
    for(auto const& p:*orders)
        append(p->toVariant());
}
void InvoiceModel::makeEntity(const QModelIndex &index, const QVariant &variant)
{
    Invoice o;
    o.fromVariant(variant);
    if(o.getIdStakeholder()==-1)
        o.setIdStakeholder(stakeholder);
    InvoiceBuilder::getInstance().build(o);
    setData(index,o.toVariant(),Roles::VariantRole);
}

void InvoiceModel::loadOrderFrom(int stakeholder)
{
    entities.reset(new vector<unique_ptr<QVariant>>);
    unique_ptr<vector<unique_ptr<Invoice>>> orders=InvoiceBuilder::getInstance().getByStakeholder(stakeholder);
    for(auto const& p:*orders)
        append(p->toVariant());
}

QVariant InvoiceModel::data(const QModelIndex &index, int role) const
{
    if(!isIndexValid(index))
        return QVariant();

    Invoice o;
    o.fromVariant(getEntity(index));
    switch (role)
    {
        case Qt::DisplayRole:
            return o.getTransactionTime().toString("d/M/yyyy hh:mm") +" "+QString::number(o.getPrice())+"$";
        case Roles::IdRole:
            return o.getId();
        case Roles::VariantRole:
            return o.toVariant();
        default:
            return QVariant();
    }
}
bool InvoiceModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(!isIndexValid(index))
        return false;

    Invoice o;
    o.fromVariant(getEntity(index));
    switch(role)
    {
        case Roles::VariantRole:
            o.fromVariant(value);
            break;
        case Roles::DeleteRole:
            o.setDeleted(value.toBool());
            break;
        case Roles::MakeEntity:
            makeEntity(index,value);
            o.fromVariant(data(index,Roles::VariantRole));
            break;
    }
    entities->at(static_cast<unsigned int>(index.row()))->setValue(o.toVariant());//save
    InvoiceBuilder::getInstance().update(o);
    emit dataChanged(index, index);
    return true;
}



