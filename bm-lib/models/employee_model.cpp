#include "employee_model.h"

using namespace std;

EmployeeModel::EmployeeModel(QObject *parent):
    AbstractListModel(parent)
{
    initEntities();
}


void EmployeeModel::initEntities()
{
    unique_ptr<vector<unique_ptr<Employee>>> employees=EmployeeBuilder::getInstance().getAll();

    for(auto const& e:*employees)
        append(e->toVariant());
}

void EmployeeModel::makeEntity(const QModelIndex &index,const QVariant& variant)
{
    Employee e;
    e.fromVariant(variant);
    EmployeeBuilder::getInstance().build(e);
    setData(index,e.toVariant(),Roles::VariantRole);
}

// QAbstractItemModel interface
QVariant EmployeeModel::data(const QModelIndex &index, int role) const
{
    if(!isIndexValid(index))
        return QVariant();
    Employee e;
    e.fromVariant(getEntity(index));
    switch (role)
    {
        case Qt::DisplayRole:
            return e.getName()+"  "+e.getForename();
        case Roles::IdRole:
            return e.getId();
        case Roles::VariantRole:
            return e.toVariant();
        default:
            return QVariant();
    }
}

bool EmployeeModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
    if(!isIndexValid(index))
        return false;

    Employee e;
    e.fromVariant(getEntity(index));
    switch(role)
    {
        case Roles::VariantRole:
            e.fromVariant(value);
            break;
        case Roles::DeleteRole:
            if(e.getType().getName()!="MANAGER")
                e.setIsDelete(value.toBool());
            else
                append(e.toVariant());
            break;
        case Roles::MakeEntity:
            makeEntity(index,value);
            e.fromVariant(data(index,Roles::VariantRole));
            break;
    }
    entities->at(static_cast<unsigned int>(index.row()))->setValue(e.toVariant());//save
    EmployeeBuilder::getInstance().update(e);
    emit dataChanged(index, index);
    return true;
}

Employee EmployeeModel::getEmployeeById(int id)
{
    return  Employee(data(getIndexById(id),VariantRole));
}
