#include "planning_model.h"
using namespace std;

PlanningModel::PlanningModel(QObject *parent):
    AbstractTableModel (5,parent)
{
    initEntities();
}
//------------- PRIVATE -------------//

void PlanningModel::initEntities()
{
    unique_ptr<vector<unique_ptr<Planning>>> plannings=db.planningDao->getAll();
    for(auto const& p:*plannings)
        append(p->toVariant());
}

void PlanningModel::makeEntity(const QModelIndex &index, const QVariant &variant)
{
    Planning p;
    p.fromVariant(variant);
    p.setIdOwner(employeeId);
    db.planningDao->create(p);
    setData(index,p.toVariant(),Roles::VariantRole);
}

void PlanningModel::loadPlanningForEmployee(int idEmployee)
{
    entities.reset(new vector<unique_ptr<QVariant>>);
    unique_ptr<vector<unique_ptr<Planning>>> plannings=db.planningDao->getPlanningByEmployee(idEmployee);
    for(auto const& p:*plannings)
        append(p->toVariant());
}

//------------- PUBLIC -------------//
void PlanningModel::setEmployeeId(int value)
{
    beginResetModel();
    employeeId = value;
    loadPlanningForEmployee(value);
    endResetModel();
}

// QAbstractItemModel interface
QVariant PlanningModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role!=Qt::DisplayRole)
        return QVariant();

    if(orientation==Qt::Horizontal)
    {
        switch (section)
        {
            case 0:
                return "Day";
            case 1:
                return "Day Off";
            case 2:
                return "Begin";
            case 3:
                return "End";
            case 4:
                return "Comment";
        default:
            return QVariant();
        }
    }
    return QVariant();
}
QVariant PlanningModel::data(const QModelIndex &index, int role) const
{
    if(!isIndexValid(index))
        return QVariant();

    Planning p;
    p.fromVariant(getEntityAtIndex(index));
    switch (role)
    {
        case Qt::DisplayRole:
            switch(index.column())
            {
            case 0:
                return p.getBegin().toString("dddd dd/M/yyyy");
            case 1:
                return p.getIsDayOff();
            case 2:
                return p.getBegin().toString();
            case 3:
                return p.getEnd().toString();
            case 4:
                return p.getComment();
            }
        break;
        case Roles::IdRole:
            return p.getId();
        case Roles::VariantRole:
            return p.toVariant();
        default:
            return QVariant();
    }
    return QVariant();
}
bool PlanningModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
    if(!isIndexValid(index))
        return false;

    Planning p;
    p.fromVariant(getEntityAtIndex(index));
    switch(role)
    {
        case Qt::EditRole:
            switch(index.column())
            {
                case 0:
                    break;
                case 1:
                    p.setIsDayOff(value.toBool());
                    break;
                case 2:
                    p.setBegin(value.toDateTime());
                    break;
                case 3:
                    p.setEnd(value.toDateTime());
                    break;
                case 4:
                    p.setComment(value.toString());
                    break;
                default: break;
            }
        break;
        case Roles::VariantRole:
            p.fromVariant(value);
            break;
        case DeleteRole:
            p.setIsDelete(value.toBool());
            break;
        case MakeEntity:
            makeEntity(index,value);
            p.fromVariant(data(index,Roles::VariantRole));
            break;
        default:
            return false;
    }
    entities->at(static_cast<unsigned int>(index.row()))->setValue(p.toVariant());//save
    db.planningDao->update(p);
    emit dataChanged(index, index);
    return true;
}

