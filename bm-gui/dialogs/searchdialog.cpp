#include "searchdialog.h"
#include "ui_searchdialog.h"

/**
 * changer la recherche !
 */
SearchDialog::SearchDialog(AbstractListModel *model,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SearchDialog)
{
    ui->setupUi(this);
    initProxyModel(model);

    connect(ui->button_valid,SIGNAL(clicked()),this,SLOT(on_valid()));
    connect(ui->button_cancel,SIGNAL(clicked()),this,SLOT(on_cancel()));
    connect(ui->line_search,SIGNAL(textChanged(const QString&)),this,SLOT(on_search(const QString&)));
}



SearchDialog::~SearchDialog()
{
    delete ui;
}
void SearchDialog::on_valid()
{
    done(1);
}
void SearchDialog::on_cancel()
{
    reject();
}

void SearchDialog::on_search(const QString &input)
{
    QRegExp exp(QRegExp(input,Qt::CaseInsensitive,QRegExp::FixedString));
    proxyModel->setFilterRegExp(exp);
    enableValidateButton();
}


QItemSelectionModel* SearchDialog::getSelectionModel()
{
    return ui->listView->selectionModel();
}

QVariant SearchDialog::getVariant()
{
    return proxyModel->data(getSelectionModel()->currentIndex(),AbstractListModel::Roles::VariantRole);
}



void SearchDialog::initProxyModel(QAbstractItemModel *model)
{
    proxyModel=new QSortFilterProxyModel(this);
    proxyModel->setSourceModel(model);
    ui->listView->setModel(proxyModel);
    setCurrentSelectionToFirst();
}



void SearchDialog::setCurrentSelectionToFirst()
{
    QModelIndex index=proxyModel->index(0,0);
    if(!index.isValid())
        return;

    ui->listView->setCurrentIndex(index);
}

void SearchDialog::enableValidateButton()
{
    if(ui->listView->currentIndex().isValid())
        ui->button_valid->setEnabled(true);
    else
        ui->button_valid->setEnabled(false);
}
