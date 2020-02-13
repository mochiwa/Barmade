#ifndef PRODUCTMANAGEMENT_PANEL_H
#define PRODUCTMANAGEMENT_PANEL_H

#include "bm-lib_global.h"
#include <QWidget>
#include <QItemSelectionModel>

#include "models/product_model.h"
#include "components/listviewcontrol.h"
#include "productform_widget.h"
#include "business/productbusiness.h"

namespace Ui {
class ProductManagementPanel;
}

class BMLIBSHARED_EXPORT ProductManagementPanel : public QWidget
{
    Q_OBJECT
public:
    explicit ProductManagementPanel(QWidget *parent = nullptr);
    ~ProductManagementPanel();

    void setProductModel(ProductModel *model);
    void setProductSelectionModel(QItemSelectionModel *selected);
private:
    void init();
    void initLayout();
    void initListControl();
    void initProductForm();
private:
    Ui::ProductManagementPanel *ui;

    ProductModel *model;
    QItemSelectionModel *selected;
    ProductBusiness *business;

    ListViewControl *listControl;
    ProductFormWidget *productForm;
};

#endif // PRODUCTMANAGEMENT_PANEL_H
