#ifndef PRODUCT_PANEL_H
#define PRODUCT_PANEL_H

#include "bm-lib_global.h"

#include <QWidget>
#include <QList>
#include <QMessageBox>
#include "models/product_model.h"
#include "components/productbutton.h"
#include "invoice_widget.h"
#include "business/productbusiness.h"
#include "business/invoicebusiness.h"

namespace Ui {
class ProductPanel;
}

class BMLIBSHARED_EXPORT ProductPanel : public QWidget
{
    Q_OBJECT

public:
    const int columnMax=5;

    explicit ProductPanel(QWidget *parent = nullptr);
    ~ProductPanel();


    void setProductModel(ProductModel *model);
    void setOrderModel(InvoiceModel *value);
    void setEmployee(const Employee &value);

private slots:
    void on_valid();
    void on_cancel();
    void showErrorProductBox(const Product&);

private:
    void init();
    void initInvoiceWidget();
    void initProductButtons();

    void clearOrderWidget();
    void clearProductButtons();
    void jumpToNewRow(int& row,int& column);
    int showConfirmBox(const QString& msg);
private:
    Ui::ProductPanel *ui;
    InvoiceWidget *invoiceWidget;
    QList<ProductButton*> productButtons;

    ProductModel *productModel;
    InvoiceModel *orderModel;
    Employee employeeConnected;

};

#endif // PRODUCT_PANEL_H
