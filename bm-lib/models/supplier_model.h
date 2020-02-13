#ifndef SUPPLIER_MODEL_H
#define SUPPLIER_MODEL_H

#include "../bm-lib_global.h"

#include "abstractlistmodel.h"
#include "entities/supplier.h"
#include "builder/supplierbuilder.h"

class BMLIBSHARED_EXPORT SupplierModel :public AbstractListModel
{
public:
    SupplierModel(QObject *parent=nullptr);
    //QModelIndex append(const Supplier& toAppend );

    QVariant data(const QModelIndex &index, int role=Qt::DisplayRole) const override;
    bool setData(const QModelIndex& index, const QVariant& value, int role) override;

protected:
    virtual void initEntities() override;
    virtual void makeEntity(const QModelIndex& index,const QVariant& variant) override;
};



#endif // SUPPLIER_MODEL_H
