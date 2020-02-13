#include "invoice_dialog.h"
#include "ui_order_dialog.h"

InvoiceDialog::InvoiceDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InvoiceDialog)
{
    ui->setupUi(this);
    initStyleSheet();
    initOrderWidget();
    initSize();
    connect(ui->button_exit,SIGNAL(clicked()),this,SLOT(reject()));

}

InvoiceDialog::~InvoiceDialog()
{
    delete ui;
}

void InvoiceDialog::setOrder(const Invoice &order)
{
    this->order=order;
    fillOrderWidget();
}

void InvoiceDialog::initSize()
{
    int width=200;
    int heigh=this->parentWidget()->height()-100;
    this->setMinimumSize(width,heigh);
}

void InvoiceDialog::initStyleSheet()
{
    QFile f(":/css/style.css");
    f.open(QFile::ReadOnly);
    this->setStyleSheet(QLatin1String(f.readAll()));
    f.close();
}

void InvoiceDialog::initOrderWidget()
{
    invoiceWidget=new InvoiceWidget(this);
    ui->layout_wdget->addWidget(invoiceWidget);
}

void InvoiceDialog::fillOrderWidget()
{
    Entity entity=DatabaseManager::getInstance().entityDao->getById(order.getIdStakeholder());
    invoiceWidget->setStakeHolder(entity);
    invoiceWidget->setTransactionTime(order.getTransactionTime());

    for(auto const& c:order.getCompositions())
    {
        Product p=DatabaseManager::getInstance().productDao->getById(c.getIdProduct());
        for(int i=0;i<c.getQuantity();++i)
            invoiceWidget->appendProduct(p);
    }
    invoiceWidget->setQuantityEditabe(false);
}
