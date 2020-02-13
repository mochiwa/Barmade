#ifndef BUSINESSINVOICE_H
#define BUSINESSINVOICE_H

#include <QObject>
#include <QMap>
#include "models/invoice_model.h"
#include "entities/invoice.h"

class InvoiceBusiness :public QObject
{
    Q_OBJECT
public:
    InvoiceBusiness(QObject *parent=nullptr);
    InvoiceBusiness(AbstractListModel *model, QObject *parent);

    QMap<int,int> getStockOrder(Invoice const& invoice);

private:
    AbstractListModel *model;
};

#endif // BUSINESSINVOICE_H
