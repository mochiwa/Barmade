#ifndef SUPPLIER_PANEL_H
#define SUPPLIER_PANEL_H
#include "bm-lib_global.h"
#include <QWidget>
#include <QListView>

#include "models/supplier_model.h"
#include "components/listviewcontrol.h"
#include "panel/invoice_panel/invoice_panel.h"
#include "supplier_widget.h"

namespace Ui {
class SupplierPanel;
}

class BMLIBSHARED_EXPORT SupplierPanel : public QWidget
{
    Q_OBJECT

public:
    explicit SupplierPanel(QWidget *parent = nullptr);
    ~SupplierPanel();

    void setSupplierModel(SupplierModel *model);
    void setSupplierSelectionModel(QItemSelectionModel* selected);

    void activeManagementPanel(bool value);

    void setInvoiceModel(InvoiceModel *value);

private:
    void init();
    void initLayout();
    void initSupplierList();
    void initSupplierWidget();
    void initInvoicePanel();

private:
    Ui::SupplierPanel *ui;
    InvoicePanel *invoicePanel;

    SupplierModel* model;
    QItemSelectionModel* selected;
    InvoiceModel *invoiceModel;


    ListViewControl *listControl;
    SupplierWidget *supplierWidget;
};

#endif // SUPPLIER_PANEL_H
