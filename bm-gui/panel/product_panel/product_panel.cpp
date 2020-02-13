#include "product_panel.h"
#include "ui_product_panel.h"

ProductPanel::ProductPanel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProductPanel)
{
    ui->setupUi(this);
    init();
    initInvoiceWidget();

    connect(ui->button_cancel,SIGNAL(clicked()),this,SLOT(on_cancel()));
    connect(ui->button_validate,SIGNAL(clicked()),this,SLOT(on_valid()));
    connect(invoiceWidget,&InvoiceWidget::hasItem,[this](bool value){ui->button_validate->setEnabled(value);});
}

ProductPanel::~ProductPanel()
{
    delete ui;
}

//------------- SLOTS -------------//

void ProductPanel::on_valid()
{
    if(showConfirmBox("Validate the order ?") != QMessageBox::Ok)
        return ;

    ProductBusiness productBusiness(productModel);
    InvoiceBusiness invoiceBusiness(orderModel);
    connect(&productBusiness,SIGNAL(stock_not_enough(const Product&)),this,SLOT(showErrorProductBox(const Product&)));
    Invoice invoice=invoiceWidget->getInvoice();

    if(productBusiness.checkStockEnough(invoiceBusiness.getStockOrder(invoice)))
    {
        for(auto const& i:invoice.getCompositions())
        {
            Product p=productModel->getById(i.getIdProduct());
            for(int qty=0;qty<i.getQuantity();++qty)
                productBusiness.processDebit(p);
        }
        QModelIndex index=orderModel->append(invoice.toVariant());
        invoice=invoiceWidget->getInvoice();
        orderModel->setData(index,invoice.toVariant(),AbstractListModel::MakeEntity);
    }
    clearOrderWidget();
}
void ProductPanel::on_cancel()
{
    if(showConfirmBox("Cancel the order ?")  != QMessageBox::Ok)
        return ;
    clearOrderWidget();
}

void ProductPanel::showErrorProductBox(const Product &p)
{
    QMessageBox *box=new QMessageBox(this);
    box->setIcon(QMessageBox::Critical);
    box->setText("The product : '"+p.getName()+"' has not enough stock ! ");
    box->exec();
    delete box;
}

//------------- PRIVATE -------------//
void ProductPanel::init()
{
    productModel=nullptr;
    orderModel=nullptr;
    invoiceWidget=nullptr;
}
void ProductPanel::initInvoiceWidget()
{
    invoiceWidget=new InvoiceWidget(this);
    ui->layout_order->addWidget(invoiceWidget);
}
void ProductPanel::initProductButtons()
{
    int column=0;
    int row=0;
    QModelIndex index=productModel->index(0,0);
    clearProductButtons();
    while(index.isValid())
    {
        ProductButton *button=ProductButton::make_ProductButton(productModel->data(index,AbstractListModel::VariantRole),this);
        productButtons.push_back(button);
        connect(button,&QPushButton::clicked,[this,button]{invoiceWidget->appendProduct(button->getProduct());});
        ui->layout_products->addWidget(button,row,column++);

        index=productModel->index(index.row()+1,0);
        if(column == columnMax)
            jumpToNewRow(row,column);
    }
}

void ProductPanel::clearOrderWidget()
{
    invoiceWidget->clear();
    invoiceWidget->setStakeHolder(employeeConnected);
}
void ProductPanel::clearProductButtons()
{
    while(QLayoutItem* item=ui->layout_products->takeAt(0))
    {
        Q_ASSERT(!item->layout());
        delete item->widget();
        delete item;
    }
    productButtons.clear();
}
void ProductPanel::jumpToNewRow(int &row, int &column)
{
    column=0;
    row++;
}
int ProductPanel::showConfirmBox(const QString &msg)
{
    QMessageBox msgBox(this);
    msgBox.setText(msg);

    msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);
    return  msgBox.exec();
}
//------------- PUBLIC -------------//

//-------- Getter & Setter ---------//
void ProductPanel::setProductModel(ProductModel *model)
{
    this->productModel=model;
    initProductButtons();

    connect(model,&QAbstractItemModel::dataChanged,[this](){initProductButtons();});
}
void ProductPanel::setOrderModel(InvoiceModel *value)
{
    orderModel = value;
}
void ProductPanel::setEmployee(const Employee &value)
{
    employeeConnected = value;
    clearOrderWidget();
}

