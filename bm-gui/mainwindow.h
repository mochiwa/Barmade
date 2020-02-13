#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "bm-lib_global.h"
#include <QMainWindow>

#include "controllers/mainwindow_controller.h"

#include "dialogs/login_dialog.h"

#include "panel/information_panel/information_panel.h"
#include "panel/employee_panel/employee_panel.h"
#include "panel/supplier_panel/supplier_panel.h"
#include "panel/product_panel/product_panel.h"
#include "panel/ProductManagementPanel/productmanagement_panel.h"
#include "panel/stock_panel/stockmanagement_panel.h"

namespace Ui {
class MainWindow;
}

class BMLIBSHARED_EXPORT MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void showloginDialog();
private:
    void init();
    void initStyleSheet();

    void initMainPanel();
    void initInformationPanel();
    void initEmployeePanel();
    void initSupplierPanel();
    void initProductPanel();
    void initProductManagementPanel();
    void initStockManagementPanel();
    void setAccessToPanel(bool isManager);
private:
    Ui::MainWindow *ui;
    QTabWidget *jobs;

    InformationPanel *informationPanel;
    EmployeePanel *employeePanel;
    SupplierPanel *supplierPanel;
    ProductPanel *productPanel;
    ProductManagementPanel *productManagementPanel;
    StockManagementPanel *stockManagementPanel;

    MainWindowController mainController;
};

#endif // MAINWINDOW_H
