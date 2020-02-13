#include "stockmanagement_panel.h"
#include "ui_stockmanagement_panel.h"

StockManagementPanel::StockManagementPanel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StockManagementPanel)
{
    ui->setupUi(this);
    init();
    initStockOrderTable();

    connect(stockOrderTable,SIGNAL(dataChange()),this ,SLOT(updateLabelTotal()));
    connect(ui->button_cancel,SIGNAL(clicked()),this,SLOT(on_cancel()));
    connect(ui->button_validate,SIGNAL(clicked()),this,SLOT(on_valid()));
}

StockManagementPanel::~StockManagementPanel()
{
    delete ui;
}

void StockManagementPanel::setProductModel(ProductModel *value)
{
    productModel = value;
    stockOrderTable->setProductModel(productModel);
}

void StockManagementPanel::setInvoiceModel(InvoiceModel *value)
{
    invoiceModel = value;
}

void StockManagementPanel::setSupplierModel(SupplierModel *value)
{
    supplierModel = value;
    ui->comboBox_supplier->setModel(supplierModel);
}

void StockManagementPanel::updateLabelTotal()
{
    double sum=static_cast<double>(stockOrderTable->sumTotalPrice());
    ui->spinBox_total->setValue(sum);
    if(sum>0)
        ui->button_validate->setEnabled(true);
    else
        ui->button_validate->setEnabled(false);
}

void StockManagementPanel::init()
{

}

void StockManagementPanel::initStockOrderTable()
{
    stockOrderTable=new ProductStockOrder(this);
    ui->layout_table->addWidget(stockOrderTable);
}

int StockManagementPanel::showConfirmBox(const QString &msg)
{
    QMessageBox msgBox(this);
    msgBox.setText(msg);

    msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);
    return  msgBox.exec();
}

int StockManagementPanel::getSupplierId()
{
    QModelIndex index;
    int selection=ui->comboBox_supplier->currentIndex();
    index=supplierModel->index(selection,0);
    return supplierModel->data(index,AbstractListModel::IdRole).toInt();
}

void StockManagementPanel::on_valid()
{
    if(showConfirmBox("Confirm the order ?")  != QMessageBox::Ok)
        return ;

    ProductBusiness business(productModel);
    Invoice invoice(stockOrderTable->build());
    invoice.setIdStakeholder(getSupplierId());
    invoice.setTransactionTime(QDateTime::currentDateTime());
    QModelIndex index=invoiceModel->append(invoice.toVariant());
    invoiceModel->setData(index,invoice.toVariant(),AbstractListModel::MakeEntity);
    invoice.fromVariant(invoiceModel->data(index,AbstractListModel::VariantRole));

    for(auto const c:invoice.getCompositions())
    {
        Product p=productModel->getById(c.getIdProduct());
        business.processCredit(p,c.getQuantity());
    }

}


void StockManagementPanel::on_cancel()
{
    if(showConfirmBox("Cancel the order ?")  != QMessageBox::Ok)
        return ;
    stockOrderTable->resetTable();
}
