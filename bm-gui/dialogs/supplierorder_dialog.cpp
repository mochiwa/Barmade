#include "supplierorder_dialog.h"
#include "ui_supplierorder_dialog.h"

SupplierOrderDialog::SupplierOrderDialog(const Product &p, SupplierModel *model, QWidget *parent):
    QDialog(parent),
    ui(new Ui::SupplierOrderDialog)
{
    ui->setupUi(this);
    this->model=model;
    this->product=p;
    init();

    connect(ui->button_validate,SIGNAL(clicked()),this,SLOT(on_validate()));
}

SupplierOrderDialog::~SupplierOrderDialog()
{
    delete ui;
}

void SupplierOrderDialog::on_validate()
{
    buildInvoice();
    if(ui->spinBox->value()>0)
        done(QDialog::Accepted);
}

void SupplierOrderDialog::init()
{
    ui->comboBox->setModel(model);
    ui->label_productValue->setText(product.getName());
    ui->label_stockValue->setNum(product.getStock());
    ui->label_alarmValue->setNum(product.getAlarm());

    ui->spinBox->setMinimum(product.getAlarm());
}

void SupplierOrderDialog::buildInvoice()
{
    int quantity=ui->spinBox->value();
    float price=getDiscountPrice()*quantity;


    std::vector<CompositionOrder> orders;
    orders.push_back(CompositionOrder(invoice.getId(),product.getId(),quantity));

    invoice.setPrice(price);
    invoice.setCompositions(orders);
    invoice.setIdStakeholder(getIdSupplier());
    invoice.setTransactionTime(QDateTime::currentDateTime());
}

float SupplierOrderDialog::getDiscountPrice()
{
    float price;
    float discount;

    price=product.getPrice();
    discount=(price*20)/100;
    return price-discount;
}

int SupplierOrderDialog::getIdSupplier()
{
    QModelIndex index;
    index=model->index(ui->comboBox->currentIndex(),0);
    return model->data(index,AbstractListModel::IdRole).toInt();
}

Invoice SupplierOrderDialog::getInvoice() const
{
    return invoice;
}
