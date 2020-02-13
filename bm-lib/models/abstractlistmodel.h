#ifndef ABSTRACTLISTMODEL_H
#define ABSTRACTLISTMODEL_H
#include "../bm-lib_global.h"
#include <QAbstractListModel>
#include <vector>
#include <memory>
#include <QVariant>
#include "sql/database_manager.h"
class BMLIBSHARED_EXPORT AbstractListModel : public QAbstractListModel
{
public:
    AbstractListModel(QObject *parent=nullptr);

    QModelIndex append(const QVariant& toAppend);
    QModelIndex getIndexOf(const QVariant& search);
    QModelIndex getIndexById(int id);

    // QAbstractItemModel interface
    enum Roles {
        IdRole = Qt::UserRole + 1,
        VariantRole= Qt::UserRole +2,
        DeleteRole= Qt::UserRole+3,
        MakeEntity=Qt::UserRole+4
    };
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    bool removeRows(int row, int count, const QModelIndex& parent) override;

protected:
    /**
     * @brief get the variant at pos index
     */
    const QVariant& getEntity(QModelIndex index) const;
    bool isIndexValid(const QModelIndex& index) const;
    /**
     * @brief fill the init data for the vector entities
     */
    virtual void initEntities()=0;
    /**
     * @brief assign to the variant at index the variant in param and insert it in bdd
     * @param index
     */
    virtual void makeEntity(const QModelIndex& index,const QVariant& variant)=0;

    DatabaseManager &db;
    std::unique_ptr<std::vector<std::unique_ptr<QVariant>>> entities;
};
#endif // ABSTRACTLISTMODEL_H
