#include "invoice_widget.h"
#include "ui_invoice_widget.h"

InvoiceWidget::InvoiceWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InvoiceWidget)
{
    ui->setupUi(this);
    init();
}

InvoiceWidget::~InvoiceWidget()
{
    delete ui;
}

//------------- PRIVATE -------------//
void InvoiceWidget::init()
{
    invoiceTable=nullptr;
    totalPrice=0;
    setTransactionTime();

    initInvoicetable();
}
#include <QDebug>
void InvoiceWidget::initInvoicetable()
{
    invoiceTable = new InvoiceTable(this);
    ui->layout_table->addWidget(invoiceTable);

    connect(invoiceTable,&AbstractTableWidget::dataChange,[this](){
        double sum=static_cast<double>(invoiceTable->sumTotalPrice());
        ui->spinbox_total->setValue(sum);
        (sum<=0) ? emit hasItem(false): emit hasItem(true);
    });
}

//------------- SLOTS -------------//
//------------- PUBLIC -------------//
void InvoiceWidget::appendProduct(const Product &p)
{
    invoiceTable->AppendObject(p.toVariant());
}

//-------- Getter & Setter ---------//
void InvoiceWidget::setStakeHolder(const Entity &entity)
{
    stakeholder=entity;
    ui->label_employee_value->setText(stakeholder.getName());
}

void InvoiceWidget::setTransactionTime(const QDateTime &date)
{
    transactionTime=date;
    ui->label_date_value->setText(date.toString("dddd d MMMM yyyy hh:mm"));
}

void InvoiceWidget::setQuantityEditabe(bool value)
{
   invoiceTable->setEnabled(value);
}

void InvoiceWidget::clear()
{
    invoiceTable->clear();
    setTransactionTime();
}

Invoice InvoiceWidget::getInvoice()
{
    Invoice order;
    order.fromVariant(invoiceTable->build());
    order.setTransactionTime(transactionTime);
    order.setIdStakeholder(stakeholder.getId());
    return order;
}







