#include "supplier_panel.h"
#include "ui_supplier_panel.h"

SupplierPanel::SupplierPanel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SupplierPanel)
{
    ui->setupUi(this);
    init();
    connect(listControl,SIGNAL(on_edit()),supplierWidget,SLOT(on_edit()));
    connect(listControl,&ListViewControl::on_edit,[this](){listControl->setEnabled(false);});
    connect(supplierWidget,&SupplierWidget::entity_editingFinsih,[this](){listControl->setEnabled(true);});
}

SupplierPanel::~SupplierPanel()
{
    delete ui;
}

void SupplierPanel::setSupplierModel(SupplierModel *model)
{
    this->model=model;
    listControl->setModel(model);
    supplierWidget->setModel(model);
}
void SupplierPanel::setSupplierSelectionModel(QItemSelectionModel* selected)
{
    this->selected=selected;
    listControl->setSelectionModel(selected);
    supplierWidget->setSelectionModel(selected);
}


void SupplierPanel::activeManagementPanel(bool value)
{
    listControl->setEditable(value);
}
void SupplierPanel::init()
{
    model=nullptr;
    selected=nullptr;
    initSupplierList();
    initSupplierWidget();
    initLayout();
    initInvoicePanel();
}

void SupplierPanel::initLayout()
{
    listControl->setMaximumWidth(500);
}
void SupplierPanel::initSupplierList()
{
    listControl=new ListViewControl(this);
    ui->layout_list->addWidget(listControl);
}
void SupplierPanel::initSupplierWidget()
{
    supplierWidget=new SupplierWidget(this);
    ui->layout_widget->addWidget(supplierWidget);
}

void SupplierPanel::initInvoicePanel()
{
    invoicePanel=new InvoicePanel(this);
    ui->layout_invoice->addWidget(invoicePanel);
}

void SupplierPanel::setInvoiceModel(InvoiceModel *value)
{
    invoiceModel = value;
    invoicePanel->setModel(invoiceModel);

    connect(selected,&QItemSelectionModel::selectionChanged,[this](const QItemSelection &selectedRow)
    {
        if(selectedRow.isEmpty())
            return;
        invoiceModel->setStakeholder(model->data(selected->currentIndex(),AbstractListModel::Roles::IdRole).toInt());
        invoicePanel->updateAmount();
    });
}
