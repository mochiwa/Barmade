#include "invoice_panel.h"
#include "ui_invoice_panel.h"

InvoicePanel::InvoicePanel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InvoicePanel)
{
    ui->setupUi(this);
    init();
    connect(ui->listView,&QAbstractItemView::clicked,this,&InvoicePanel::showInvoiceDialog);
    connect(ui->date_begin,SIGNAL(dateChanged(const QDate &)),this,SLOT(on_search()));
    connect(ui->date_end,SIGNAL(dateChanged(const QDate &)),this,SLOT(on_search()));

}

InvoicePanel::~InvoicePanel()
{
    delete ui;
}


void InvoicePanel::setModel(AbstractListModel *model)
{
    this->model=static_cast<InvoiceModel*>(model);
    proxyModel->setSourceModel(model);
    ui->listView->setModel(proxyModel);
    updateAmount();
}

void InvoicePanel::setSelectionModel(QItemSelectionModel *selection)
{
    this->selection=selection;
    ui->listView->setSelectionModel(selection);
    selection->clearCurrentIndex();
}

void InvoicePanel::updateAmount()
{
    QModelIndex index;
    Invoice invoice;
    float amount=0;
    for(int i=0;i<proxyModel->rowCount();++i)
    {
        index=proxyModel->index(i,0);
        invoice.fromVariant(proxyModel->data(index,AbstractListModel::VariantRole));
        amount+=invoice.getPrice();
    }
    ui->spinBox_total->setValue(amount);
}

void InvoicePanel::init()
{
    proxyModel=new InvoiceProxySortModel(this);
    ui->date_begin->setDate(QDate::currentDate());
    ui->date_end->setDate(QDate::currentDate());
    initStyleSheet();
}

void InvoicePanel::initStyleSheet()
{
    QFile f(":/css/list_invoice.css");
    f.open(QFile::ReadOnly);
    this->setStyleSheet(QLatin1String(f.readAll()));
    f.close();
}

void InvoicePanel::dateManagement()
{
    QDate begin=ui->date_begin->date();
    QDate end=ui->date_end->date();

    if(end>QDate::currentDate())
        end=QDate::currentDate();

    if(begin>end)
        begin=end;
    ui->date_begin->setDate(begin);
    ui->date_end->setDate(end);

}

void InvoicePanel::showInvoiceDialog()
{
    InvoiceDialog *dialog=new InvoiceDialog(this);
    Invoice invoice;
    invoice.fromVariant(proxyModel->data(ui->listView->currentIndex(),AbstractListModel::Roles::VariantRole));

    dialog->setOrder(invoice);
    dialog->exec();
    delete dialog;
}

void InvoicePanel::on_search()
{
    dateManagement();

    proxyModel->setFilterMinimumDate(ui->date_begin->date());
    proxyModel->setFilterMaximumDate(ui->date_end->date());
    updateAmount();
}
