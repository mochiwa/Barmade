#ifndef ABSTRACTTABLEMODEL_H
#define ABSTRACTTABLEMODEL_H

#include "bm-lib_global.h"
#include <QAbstractTableModel>
#include <memory>
#include <QVariant>
#include "sql/database_manager.h"

class BMLIBSHARED_EXPORT AbstractTableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    AbstractTableModel(int countColumn=0,QObject *parent=nullptr);
    virtual ~AbstractTableModel();
    QModelIndex append(const QVariant& toAppend);
    QModelIndex getIndexOf(const QVariant& search);
    const QVariant& getEntityAtIndex(QModelIndex index) const;

    // QAbstractItemModel interface
    enum Roles {
        IdRole = Qt::UserRole + 1,
        VariantRole= Qt::UserRole +2,
        DeleteRole= Qt::UserRole+3,
        MakeEntity=Qt::UserRole+4
    };
    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    virtual int columnCount(const QModelIndex &parent =QModelIndex()) const override;
    virtual bool removeRows(int row, int count, const QModelIndex& parent) override;
    virtual Qt::ItemFlags flags(const QModelIndex &index) const override;

protected:
    bool isIndexValid(const QModelIndex& index) const;
    virtual void initEntities()=0;
    virtual void makeEntity(const QModelIndex& index,const QVariant& variant)=0;


protected:
    int countColumn;
    DatabaseManager &db;
    std::unique_ptr<std::vector<std::unique_ptr<QVariant>>> entities;
};

#endif // ABSTRACTTABLEMODEL_H
