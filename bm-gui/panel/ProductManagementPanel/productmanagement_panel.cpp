#include "productmanagement_panel.h"
#include "ui_productmanagement_panel.h"

ProductManagementPanel::ProductManagementPanel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProductManagementPanel)
{
    ui->setupUi(this);
    init();
}

ProductManagementPanel::~ProductManagementPanel()
{
    delete ui;
}
#include <QDebug>
void ProductManagementPanel::init()
{
    model=nullptr;
    selected=nullptr;
    business=new ProductBusiness(this);
    initListControl();
    initProductForm();
    initLayout();

    connect(listControl,SIGNAL(on_edit()),productForm,SLOT(on_edit()));
    connect(listControl,&ListViewControl::on_edit,[this](){listControl->setEnabled(false);});
    connect(productForm,&ProductFormWidget::entity_editingFinsih,[this](){listControl->setEnabled(true);});
}
void ProductManagementPanel::initLayout()
{
    listControl->setMaximumWidth(500);
}
void ProductManagementPanel::initListControl()
{
    listControl = new ListViewControl(this);
    ui->layout_list->addWidget(listControl);
}

void ProductManagementPanel::initProductForm()
{
    productForm=new ProductFormWidget(this);
    ui->layout_widget->addWidget(productForm);
}
void ProductManagementPanel::setProductModel(ProductModel *model)
{
    this->model=model;
    listControl->setModel(model);
    productForm->setModel(model);
}
void ProductManagementPanel::setProductSelectionModel(QItemSelectionModel *selected)
{
    this->selected=selected;
    listControl->setSelectionModel(selected);
    productForm->setSelectionModel(selected);
    listControl->selectFirstElement();
}
