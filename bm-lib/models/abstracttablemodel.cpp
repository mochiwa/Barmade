#include "abstracttablemodel.h"
using namespace std;

AbstractTableModel::AbstractTableModel(int countColumn,QObject *parent):
    QAbstractTableModel(parent),
    db(DatabaseManager::getInstance()),
    entities(new vector<unique_ptr<QVariant>>)
{
    this->countColumn=countColumn;
}

AbstractTableModel::~AbstractTableModel()
{

}
//------------- PRIVATE -------------//
bool AbstractTableModel::isIndexValid(const QModelIndex& index) const
{
    if(index.row()<0 || index.row()>rowCount())
        return false;
    if(index.column()<0 || index.column()>columnCount())
        return false;
    return true;
}

//------------- PUBLIC -------------//

const QVariant& AbstractTableModel::getEntityAtIndex(QModelIndex index) const
{
    return *entities->at(static_cast<unsigned int>(index.row()));
}

QModelIndex AbstractTableModel::append(const QVariant& toAppend)
{
    int lastIndex=rowCount();
    beginInsertRows(QModelIndex(),lastIndex,lastIndex);//notify the view
    std::unique_ptr<QVariant> entity(new QVariant(toAppend));
    entities->push_back(std::move(entity));
    endInsertRows();
    return this->index(lastIndex,0);
}

QModelIndex AbstractTableModel::getIndexOf(const QVariant& search)
{
    int index=0;
    for(auto const& e:*entities)
        if(*e==search)
            return this->index(index,0);
        else
            index++;
    return this->index(0,0);
}

// QAbstractItemModel interface
int AbstractTableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return static_cast<int>(entities->size());
}

int AbstractTableModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return countColumn;
}

bool AbstractTableModel::removeRows(int row, int count, const QModelIndex& parent)
{
    if(row<0 || row>rowCount() || count<=0 || (row+count)> rowCount())
        return false;

    beginRemoveRows(parent,row,row+count-1);//happend -1?
    entities->erase(entities->begin()+row,entities->begin()+row+count);
    endRemoveRows();
    emit dataChanged(parent,parent);
    return true;
}

Qt::ItemFlags AbstractTableModel::flags(const QModelIndex &index) const
{
    if(!isIndexValid(index))
        return Qt::ItemIsEditable;
    return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
}
