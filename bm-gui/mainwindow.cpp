#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    mainController(this)
{
    ui->setupUi(this);
    init();
}

MainWindow::~MainWindow()
{
    delete ui;
}


//------------- SLOTS -------------//

//------------- PRIVATE -------------//
void MainWindow::init()
{
    initStyleSheet();
    initInformationPanel();
    initMainPanel();
    initEmployeePanel();
    initSupplierPanel();
    initProductPanel();
    initProductManagementPanel();
    initStockManagementPanel();
   // jobs->setCurrentWidget(productPanel);
}

void MainWindow::initStyleSheet()
{
    QFile f(":/css/style.css");
    f.open(QFile::ReadOnly);
    this->setStyleSheet(QLatin1String(f.readAll()));
    f.close();
}

void MainWindow::initMainPanel()
{
    jobs=new QTabWidget(this);
    jobs->setIconSize(QSize(25,25));
    ui->mainLayout->addWidget(jobs);
}
void MainWindow::initInformationPanel()
{
    informationPanel = new InformationPanel(this);
    ui->mainLayout->addWidget(informationPanel);
    connect(informationPanel,SIGNAL(logout()),this,SLOT(showloginDialog()));
}
void MainWindow::initEmployeePanel()
{
    employeePanel=new EmployeePanel(jobs);

    employeePanel->setEmployeeModel(mainController.getEmployeeModel());
    employeePanel->setEmployeeSelectionModel(mainController.getEmployeeSelection());

    employeePanel->setPlanningModel(mainController.getPlanningModel());
    employeePanel->setPlanningSelectionModel(mainController.getPlanningSelection());

    employeePanel->setInvoiceModel(mainController.getInvoiceModel());

    jobs->addTab(employeePanel,QIcon(":/images/tab_icon/users_icon.png"),"Employee");
}
void MainWindow::initSupplierPanel()
{
    supplierPanel=new SupplierPanel(jobs);

    supplierPanel->setSupplierModel(mainController.getSupplierModel());
    supplierPanel->setSupplierSelectionModel(mainController.getSupplierSelection());

    supplierPanel->setInvoiceModel(mainController.getInvoiceModel());

    jobs->addTab(supplierPanel,QIcon(":/images/tab_icon/suppliers.png"),"Supplier");
}
void MainWindow::initProductPanel()
{
    productPanel=new ProductPanel(jobs);

    productPanel->setProductModel(mainController.getProductModel());
    productPanel->setOrderModel(mainController.getInvoiceModel());

    jobs->addTab(productPanel,"Products");
}
void MainWindow::initProductManagementPanel()
{
    productManagementPanel=new ProductManagementPanel(jobs);

    productManagementPanel->setProductModel(mainController.getProductModel());
    productManagementPanel->setProductSelectionModel(mainController.getProductSelection());

    jobs->addTab(productManagementPanel,"Product Management");
}
void MainWindow::initStockManagementPanel()
{
    stockManagementPanel=new StockManagementPanel(this);

    stockManagementPanel->setInvoiceModel(mainController.getInvoiceModel());
    stockManagementPanel->setProductModel(mainController.getProductModel());
    stockManagementPanel->setSupplierModel(mainController.getSupplierModel());

    jobs->addTab(stockManagementPanel,"Stock Management");
}

void MainWindow::setAccessToPanel(bool isManager)
{
    employeePanel->activeManagementPanel(isManager);
    supplierPanel->activeManagementPanel(isManager);
    jobs->setTabEnabled(jobs->indexOf(productManagementPanel),isManager);
    jobs->setTabEnabled(jobs->indexOf(stockManagementPanel),isManager);
}
//------------- PUBLIC -------------//
void MainWindow::showloginDialog()
{
    LoginDialog loginDialog(this);
    QGraphicsBlurEffect *blurEffect=new QGraphicsBlurEffect(&loginDialog);
    blurEffect->setBlurRadius(5);
    ui->mainPanel->setGraphicsEffect(blurEffect);

    if(!loginDialog.exec())
        exit(1);

    ui->mainPanel->setGraphicsEffect(0);
    mainController.setEmployeeConnected(loginDialog.getEmployee());
    setAccessToPanel(mainController.isEmployeeConnectedManager());
    informationPanel->setEmployee(mainController.getEmployeeConnected());
}

//-------- Getter & Setter ---------//
