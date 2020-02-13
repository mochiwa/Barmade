#include "abstractlistmodel.h"
using namespace std;
AbstractListModel::AbstractListModel(QObject *parent):
    QAbstractListModel (parent),
    db(DatabaseManager::getInstance()),
    entities(new vector<unique_ptr<QVariant>>)
{
}

//------------- PRIVATE -------------//
bool AbstractListModel::isIndexValid(const QModelIndex& index)const
{
    if(index.row()<0 || index.row()>rowCount())
        return false;
    return true;
}

//------------- PUBLIC -------------//

QModelIndex AbstractListModel::append(const QVariant& toAppend)
{
    int lastIndex=rowCount();
    beginInsertRows(QModelIndex(),lastIndex,lastIndex);//notify the view
    std::unique_ptr<QVariant> entity(new QVariant(toAppend));
    entities->push_back(std::move(entity));
    endInsertRows();
    return this->index(lastIndex,0);
}

QModelIndex AbstractListModel::getIndexOf(const QVariant& search)
{
    int index=0;
    for(auto const& e:*entities)
        if(*e==search)
            return this->index(index,0);
        else
            index++;
    return this->index(-1,-1);
}

QModelIndex AbstractListModel::getIndexById(int id)
{
    for(int i=0;i<rowCount();++i)
    {
        if(id==data(index(i,0),Roles::IdRole))
            return index(i,0);
    }
    return index(-1,-1);
}

// QAbstractItemModel interface
int AbstractListModel::rowCount(const QModelIndex &parent)const
{
    Q_UNUSED(parent);
    return static_cast<int>(entities->size());
}

bool AbstractListModel::removeRows(int row, int count, const QModelIndex& parent)
{
    if(row<0 || row>rowCount() || count<=0 || (row+count)> rowCount())
        return false;
    beginRemoveRows(parent,row,count+row);
    entities->erase(entities->begin()+row,entities->begin()+row+count);
    endRemoveRows();
    return true;
}

const QVariant& AbstractListModel::getEntity(QModelIndex index) const
{
    return *entities->at(static_cast<unsigned int>(index.row()));
}


