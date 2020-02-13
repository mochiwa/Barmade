#include "invoice_proxysortmodel.h"

InvoiceProxySortModel::InvoiceProxySortModel(QObject *parent):
    QSortFilterProxyModel (parent)
{

}


//------------- SLOTS -------------//

//------------- PRIVATE -------------//
bool InvoiceProxySortModel::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const
{
    QModelIndex index=sourceModel()->index(source_row,0,source_parent);
    Invoice invoice(sourceModel()->data(index,AbstractListModel::VariantRole));
    QDate date=invoice.getTransactionTime().date();
    return dateInRange(date);
}

bool InvoiceProxySortModel::lessThan(const QModelIndex &source_left, const QModelIndex &source_right) const
{
    QVariant leftData=sourceModel()->data(source_left);
    QVariant rightData=sourceModel()->data(source_right);

    return leftData.toDateTime() < rightData.toDateTime();
}
bool InvoiceProxySortModel::dateInRange(const QDate& date) const
{
    return (!minDate.isValid() || date >= minDate) && (!maxDate.isValid() || date <= maxDate);

}
//------------- PUBLIC -------------//
QDate InvoiceProxySortModel::filterMinimumDate() const
{
    return minDate;
}
void InvoiceProxySortModel::setFilterMinimumDate(const QDate& date)
{
    minDate=date;
    invalidateFilter();
}

QDate InvoiceProxySortModel::filterMaximumDate() const
{
    return maxDate;
}
void InvoiceProxySortModel::setFilterMaximumDate(const QDate& date)
{
    maxDate=date;
    invalidateFilter();
}
//-------- Getter & Setter ---------//
