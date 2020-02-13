#ifndef MAINWINDOW_CONTROLLER_H
#define MAINWINDOW_CONTROLLER_H

#include <QObject>
#include <QItemSelectionModel>

#include "business/login_business.h"

#include "models/employee_model.h"
#include "models/planning_model.h"
#include "models/supplier_model.h"
#include "models/product_model.h"
#include "models/invoice_model.h"

class MainWindowController : public QObject
{
    Q_OBJECT
public:
    MainWindowController(QObject *parent=nullptr);
    ~MainWindowController();

    EmployeeModel *getEmployeeModel() const;
    PlanningModel *getPlanningModel() const;
    SupplierModel *getSupplierModel() const;
    ProductModel *getProductModel() const;
    InvoiceModel *getInvoiceModel() const;

    QItemSelectionModel *getEmployeeSelection() const;
    QItemSelectionModel *getPlanningSelection() const;
    QItemSelectionModel *getSupplierSelection() const;
    QItemSelectionModel *getProductSelection() const;
    QItemSelectionModel *getInvoiceSelection() const;

    Employee getEmployeeConnected() const;
    void setEmployeeConnected(const Employee &value);
    bool isEmployeeConnectedManager();

protected:
    void init();
    void initModels();
    void initSelectionModels();


private:
    EmployeeModel *employeeModel;
    PlanningModel *planningModel;
    SupplierModel *supplierModel;
    ProductModel *productModel;
    InvoiceModel  *invoiceModel;

    QItemSelectionModel *employeeSelection;
    QItemSelectionModel *planningSelection;
    QItemSelectionModel *supplierSelection;
    QItemSelectionModel *productSelection;
    QItemSelectionModel *invoiceSelection;

    Employee employeeConnected;
};

#endif // MAINWINDOW_CONTROLLER_H
