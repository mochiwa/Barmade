#ifndef STOCKMANAGEMENT_PANEL_H
#define STOCKMANAGEMENT_PANEL_H

#include "bm-lib_global.h"
#include <QWidget>

#include "models/product_model.h"
#include "models/invoice_model.h"
#include "models/supplier_model.h"

#include "productstockorder.h"
#include "QMessageBox"
#include <business/productbusiness.h>


namespace Ui {
class StockManagementPanel;
}

class BMLIBSHARED_EXPORT StockManagementPanel : public QWidget
{
    Q_OBJECT

public:
    explicit StockManagementPanel(QWidget *parent = nullptr);
    ~StockManagementPanel();

    void setProductModel(ProductModel *value);
    void setInvoiceModel(InvoiceModel *value);
    void setSupplierModel(SupplierModel *value);

public slots:
    void updateLabelTotal();
    void on_valid();
    void on_cancel();

private:
    void init();
    void initStockOrderTable();
    int showConfirmBox(const QString& msg);

    int getSupplierId();

private:
    Ui::StockManagementPanel *ui;
    ProductStockOrder *stockOrderTable;

    ProductModel *productModel;
    InvoiceModel *invoiceModel;
    SupplierModel *supplierModel;
};

#endif // STOCKMANAGEMENT_PANEL_H
