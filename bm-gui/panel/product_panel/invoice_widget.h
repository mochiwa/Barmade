#ifndef ORDERWIDGET_H
#define ORDERWIDGET_H

#include <QWidget>
#include "invoicetable_widget.h"
#include "models/invoice_model.h"

namespace Ui {
class InvoiceWidget;
}

class InvoiceWidget : public QWidget
{
    Q_OBJECT

public:
    explicit InvoiceWidget(QWidget *parent = nullptr);
    ~InvoiceWidget();

    void setStakeHolder(const Entity & entity);
    void appendProduct(const Product& p);

    //QDateTime getTransactionTime() const;
    void setTransactionTime(const QDateTime& date=QDateTime::currentDateTime());
    void setQuantityEditabe(bool);
    void clear();
    Invoice getInvoice();
protected:
    void init();
    void initInvoicetable();
signals:
    void hasItem(bool);

private:
    Ui::InvoiceWidget *ui;
    InvoiceTable * invoiceTable;

    float totalPrice;
    QDateTime transactionTime;
    Entity stakeholder;

};

#endif // ORDERWIDGET_H
