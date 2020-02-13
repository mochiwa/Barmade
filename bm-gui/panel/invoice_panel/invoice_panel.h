#ifndef INVOICE_PANEL_H
#define INVOICE_PANEL_H
#include "bm-lib_global.h"
#include <QWidget>
#include <QItemSelectionModel>
#include "models/invoice_model.h"
#include "dialogs/invoice_dialog.h"
#include "invoice_proxysortmodel.h"

namespace Ui {
class InvoicePanel;
}

class BMLIBSHARED_EXPORT InvoicePanel : public QWidget
{
    Q_OBJECT

public:
    explicit InvoicePanel(QWidget *parent = nullptr);
    ~InvoicePanel();

    void setModel(AbstractListModel *model);
    void setSelectionModel(QItemSelectionModel *selection);
    void updateAmount();
private:
    void init();
    void initStyleSheet();
    void dateManagement();
private slots:
    void showInvoiceDialog();
    void on_search();
private:
    Ui::InvoicePanel *ui;

    InvoiceModel * model;
    InvoiceProxySortModel *proxyModel;
    QItemSelectionModel *selection;
};

#endif // INVOICE_PANEL_H
