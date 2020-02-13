#ifndef INVOICE_PROXYSORTMODEL_H
#define INVOICE_PROXYSORTMODEL_H

#include <QSortFilterProxyModel>
#include <QDate>
#include "entities/invoice.h"
#include "models/abstractlistmodel.h"
class InvoiceProxySortModel : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    InvoiceProxySortModel(QObject *parent=nullptr);

    QDate filterMinimumDate() const;
    void setFilterMinimumDate(const QDate& date);

    QDate filterMaximumDate() const;
    void setFilterMaximumDate(const QDate& date);

protected:
    virtual bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const;
    virtual bool lessThan(const QModelIndex &source_left, const QModelIndex &source_right) const;

private:
    bool dateInRange(const QDate& date) const;
private:
    QDate minDate;
    QDate maxDate;

    // QSortFilterProxyModel interface
};

#endif // INVOICE_PROXYSORTMODEL_H
