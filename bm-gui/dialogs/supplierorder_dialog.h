#ifndef SUPPLIERORDER_DIALOG_H
#define SUPPLIERORDER_DIALOG_H

#include <QDialog>
#include "models/supplier_model.h"
#include "entities/invoice.h"
#include "entities/product.h"

namespace Ui {
class SupplierOrderDialog;
}

class SupplierOrderDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SupplierOrderDialog(const Product& p, SupplierModel*model,QWidget *parent = nullptr);
    ~SupplierOrderDialog();

    Invoice getInvoice() const;

public slots:
    void on_validate();

protected:
    void init();
    void buildInvoice();
    float getDiscountPrice();
    int getIdSupplier();
private:
    Ui::SupplierOrderDialog *ui;

    SupplierModel*model;
    Product product;
    Invoice invoice;

};



#endif // SUPPLIERORDER_DIALOG_H
