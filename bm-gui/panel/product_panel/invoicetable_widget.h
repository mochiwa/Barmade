#ifndef ORDERTABLE_WIDGET_H
#define ORDERTABLE_WIDGET_H

#include "components/abstracttablewidget.h"
#include "components/tablewidgetspinbox_delegate.h"
#include "entities/product.h"
#include <entities/invoice.h>

class InvoiceTable : public AbstractTableWidget
{
    Q_OBJECT
public:
    enum Column{Name,Quantity,Price,Total};
    const int columnCount=4;

    InvoiceTable(QWidget *parent =nullptr);
    ~InvoiceTable();

    QVariant build();

    float sumTotalPrice();

public slots:
    void updateLine(int row);

    void on_updateData(int,int);

protected:
    virtual void initColumns();
    virtual void createRow(int row);
    virtual void incrementQuantity(int row);

    int getQuantity(int row);
};


#endif // ORDERTABLE_WIDGET_H
