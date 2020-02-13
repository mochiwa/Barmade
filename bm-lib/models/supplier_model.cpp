#include "supplier_model.h"

using namespace std;
SupplierModel::SupplierModel(QObject *parent):
    AbstractListModel(parent)
{
    initEntities();
}
void SupplierModel::initEntities()
{
    unique_ptr<vector<unique_ptr<Supplier>>> suppliers=SupplierBuilder::getInstance().getAll();

    for(auto const& s:*suppliers)
        append(s->toVariant());
}

void SupplierModel::makeEntity(const QModelIndex &index,const QVariant& variant)
{
    Supplier s;
    s.fromVariant(variant);
    SupplierBuilder::getInstance().build(s);
    setData(index,s.toVariant(),Roles::VariantRole);
}

// QAbstractItemModel interface
QVariant SupplierModel::data(const QModelIndex &index, int role) const
{
    if(!isIndexValid(index))
        return QVariant();

    Supplier s;
    s.fromVariant(getEntity(index));
    switch (role)
    {
        case Qt::DisplayRole:
            return s.getName();
        case Roles::IdRole:
            return s.getId();
        case Roles::VariantRole:
            return s.toVariant();
        default:
            return QVariant();
    }
}

bool SupplierModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
    if(!isIndexValid(index))
        return false;

    Supplier s;
    s.fromVariant(getEntity(index));//load
    switch(role)
    {
        case Roles::VariantRole:
            s.fromVariant(value);
            break;
        case Roles::DeleteRole:
            s.setIsDelete(value.toBool());
            break;
        case Roles::MakeEntity:
            makeEntity(index,value);
            s.fromVariant(data(index,Roles::VariantRole));
            break;
    }
    entities->at(static_cast<unsigned int>(index.row()))->setValue(s.toVariant());//save
    SupplierBuilder::getInstance().update(s);
    emit dataChanged(index, index);
    return true;
}
