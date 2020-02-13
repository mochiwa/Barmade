#include "mainwindow_controller.h"

MainWindowController::MainWindowController(QObject *parent):
    QObject (parent)
{
    init();
}

MainWindowController::~MainWindowController()
{
}





//------------- SLOTS -------------//
void MainWindowController::init()
{
    initModels();
    initSelectionModels();
}
void MainWindowController::initModels()
{
    employeeModel = new EmployeeModel(this);
    planningModel = new PlanningModel(this);
    supplierModel = new SupplierModel(this);
    productModel  = new ProductModel(this);
    invoiceModel  = new InvoiceModel(this);
}
void MainWindowController::initSelectionModels()
{
    employeeSelection=new QItemSelectionModel(employeeModel,this);
    planningSelection=new QItemSelectionModel(planningModel,this);
    supplierSelection=new QItemSelectionModel(supplierModel,this);
    productSelection=new QItemSelectionModel(productModel,this);
    invoiceSelection=new QItemSelectionModel(invoiceModel,this);
}

Employee MainWindowController::getEmployeeConnected() const
{
    return employeeConnected;
}

void MainWindowController::setEmployeeConnected(const Employee &value)
{
    employeeConnected = value;
    employeeSelection->setCurrentIndex(employeeModel->getIndexById(employeeConnected.getId()),QItemSelectionModel::SelectCurrent);
}

bool MainWindowController::isEmployeeConnectedManager()
{
    QString typeName=employeeConnected.getType().getName();
    return !typeName.compare("MANAGER");
}

//------------- PRIVATE -------------//

//------------- PUBLIC -------------//

//-------- Getter & Setter ---------//
QItemSelectionModel *MainWindowController::getInvoiceSelection() const
{
    return invoiceSelection;
}
QItemSelectionModel *MainWindowController::getProductSelection() const
{
    return productSelection;
}
QItemSelectionModel *MainWindowController::getSupplierSelection() const
{
    return supplierSelection;
}
QItemSelectionModel *MainWindowController::getPlanningSelection() const
{
    return planningSelection;
}
QItemSelectionModel *MainWindowController::getEmployeeSelection() const
{
    return employeeSelection;
}
EmployeeModel *MainWindowController::getEmployeeModel() const
{
    return employeeModel;
}
PlanningModel *MainWindowController::getPlanningModel() const
{
    return planningModel;
}
SupplierModel *MainWindowController::getSupplierModel() const
{
    return supplierModel;
}
ProductModel *MainWindowController::getProductModel() const
{
    return productModel;
}
InvoiceModel *MainWindowController::getInvoiceModel() const
{
    return invoiceModel;
}
