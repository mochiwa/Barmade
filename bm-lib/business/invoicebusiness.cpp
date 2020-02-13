#include "invoicebusiness.h"

InvoiceBusiness::InvoiceBusiness(QObject *parent):
    QObject (parent)
{

}

InvoiceBusiness::InvoiceBusiness(AbstractListModel *model, QObject *parent):
    QObject (parent)
{
    this->model=model;
}

QMap<int, int> InvoiceBusiness::getStockOrder(Invoice const& invoice)
{
    QMap<int,int> map;
    for(auto const& c:invoice.getCompositions())
        map.insert(c.getIdProduct(),c.getQuantity());
    return map;
}
