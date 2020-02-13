#include "employee_panel.h"
#include "ui_employee_panel.h"

EmployeePanel::EmployeePanel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::employeePanel)
{
    ui->setupUi(this);
    init();
}

EmployeePanel::~EmployeePanel()
{
    delete ui;
}

//------------- SLOTS -------------//


//------------- PRIVATE -------------//
void EmployeePanel::init()
{
    employeModel=nullptr;
    employeeSelected=nullptr;
    planningModel=nullptr;
    planningSelected=nullptr;
    invoiceModel=nullptr;

    initEmployeeList();
    initInvoicePanel();
    initPlanningList();
    initEmployeeWidget();
    initLayout();

    connect(listControlEmployee,SIGNAL(on_edit()),employeeWidget,SLOT(on_edit()));
    connect(listControlEmployee,&ListViewControl::on_edit,[this](){listControlEmployee->setEnabled(false);});
    connect(employeeWidget,&EmployeeWidget::entity_editingFinsih,[this](){listControlEmployee->setEnabled(true);});
}

void EmployeePanel::initLayout()
{
}

void EmployeePanel::initEmployeeList()
{
    listControlEmployee=new ListViewControl(this);
    ui->layout_listemployee->addWidget(listControlEmployee);
}

void EmployeePanel::initEmployeeWidget()
{
    employeeWidget=new EmployeeWidget(this);
    ui->layout_widgetEmployee->addWidget(employeeWidget);
}

void EmployeePanel::initInvoicePanel()
{
    invoicePanel=new InvoicePanel(this);
    ui->layout_listOrder->addWidget(invoicePanel);
}

void EmployeePanel::initPlanningList()
{
    planningViewControl=new PlanningViewControl(this);
    ui->layout_widgetEmployee->addWidget(planningViewControl);
}

//------------- PUBLIC -------------//
void EmployeePanel::activeManagementPanel(bool value)
{
    if(value)
        listControlEmployee->show();
    else
        listControlEmployee->hide();
    planningViewControl->setEditable(value);
}

//-------- Getter & Setter ---------//
void EmployeePanel::setEmployeeModel(EmployeeModel *model)
{
    employeModel=model;
    listControlEmployee->setModel(employeModel);
    employeeWidget->setModel(employeModel);
}

void EmployeePanel::setEmployeeSelectionModel(QItemSelectionModel *selected)
{
    employeeSelected=selected;
    listControlEmployee->setSelectionModel(employeeSelected);
    employeeWidget->setSelectionModel(employeeSelected);
    connect(employeeSelected,&QItemSelectionModel::selectionChanged,[this](const QItemSelection &selected)
    {
        if(selected.isEmpty())
            return;
        invoiceModel->setStakeholder(employeModel->data(employeeSelected->currentIndex(),AbstractListModel::Roles::IdRole).toInt());
        invoicePanel->updateAmount();
    });
}

void EmployeePanel::setPlanningModel(PlanningModel *model)
{
    planningModel=model;
    planningViewControl->setModel(model);
}

void EmployeePanel::setPlanningSelectionModel(QItemSelectionModel *selected)
{
    planningSelected=selected;
    planningViewControl->setSelection(selected);
    connect(employeeSelected,&QItemSelectionModel::currentChanged,[this]()
    {
        planningViewControl->on_load(employeModel->data(employeeSelected->currentIndex(),AbstractListModel::Roles::IdRole).toInt());
    });
}

void EmployeePanel::setInvoiceModel(InvoiceModel *value)
{
    invoiceModel=value;
    invoicePanel->setModel(invoiceModel);
}

void EmployeePanel::setInvoiceSelected(QItemSelectionModel *value)
{
    invoicePanel->setSelectionModel(value);
}


