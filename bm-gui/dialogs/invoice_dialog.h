#ifndef ORDER_DIALOG_H
#define ORDER_DIALOG_H

#include <QDialog>
#include "panel/product_panel/invoice_widget.h"
#include "sql/database_manager.h"

namespace Ui {
class InvoiceDialog;
}

class InvoiceDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InvoiceDialog(QWidget *parent = nullptr);
    ~InvoiceDialog();

    void setOrder(const Invoice& order);

protected:
    void initSize();
    void initStyleSheet();
    void initOrderWidget();
    void fillOrderWidget();
private:
    Ui::InvoiceDialog *ui;
    InvoiceWidget *invoiceWidget;

    Invoice order;
};

#endif // ORDER_DIALOG_H
