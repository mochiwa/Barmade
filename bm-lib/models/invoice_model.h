#ifndef ORDER_MODEL_H
#define ORDER_MODEL_H


#include "abstractlistmodel.h"
#include "entities/invoice.h"
#include "builder/invoicebuilder.h"
class InvoiceModel : public AbstractListModel
{
public:
    InvoiceModel(QObject *parent=nullptr);
    void setStakeholder(int id);


    virtual QVariant data(const QModelIndex &index, int role) const;
    virtual bool setData(const QModelIndex &index, const QVariant &value, int role);
protected:
    virtual void initEntities();
    virtual void makeEntity(const QModelIndex &index, const QVariant &variant);
    void loadOrderFrom(int stakeholder);
private:
    int stakeholder;
};


#endif // ORDER_MODEL_H
