#include "listviewcontrol.h"
#include "ui_listviewcontrol.h"

ListViewControl::ListViewControl(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ListViewControl)
{
    ui->setupUi(this);
    initStyleSheet();
    init();
}

ListViewControl::~ListViewControl()
{
    delete ui;
}
//------------- SLOTS -------------//
void ListViewControl::on_create()
{
    if(!model)
        return;
    QVariant variant;
    QModelIndex index=model->append(variant);
    ui->listView->setCurrentIndex(index);
    emit on_edit();
}
void ListViewControl::on_delete()
{
    if(selection->selectedIndexes().isEmpty() || !confirmSuppresionBox())
        return;

    int row;
    row=selection->currentIndex().row();
    model->setData(selection->currentIndex(),true,AbstractListModel::Roles::DeleteRole);
    model->removeRows(row,1,QModelIndex());

    //reassign the current index (previous/next/null)
    if(model->index(row-1,0).isValid())
        selection->setCurrentIndex(model->index(row-1,0),QItemSelectionModel::SelectCurrent);
    else if(model->index(row,0).isValid())
        selection->setCurrentIndex(model->index(row,0),QItemSelectionModel::SelectCurrent);
    else
        selection->reset();
}
//------------- PRIVATE -------------//
void ListViewControl::init()
{
    connect(ui->button_create,SIGNAL(clicked()),this,SLOT(on_create()));
    connect(ui->button_edit,&QPushButton::clicked,[this](){
        if(selection->currentIndex().isValid())
            emit on_edit();
    });
    connect(ui->button_delete,SIGNAL(clicked()),this,SLOT(on_delete()));
}
void ListViewControl::initStyleSheet()
{
    QFile f(":/css/list_control.css");
    f.open(QFile::ReadOnly);
    this->setStyleSheet(QLatin1String(f.readAll()));
    f.close();
}

bool ListViewControl::confirmSuppresionBox()
{
    QMessageBox confirmBox(this);
    confirmBox.setText("Do you want to erase "+model->data(selection->currentIndex(),Qt::DisplayRole).toString()+" ?");
    confirmBox.setStandardButtons(QMessageBox::Cancel |QMessageBox::Yes);
    if(confirmBox.exec()==QMessageBox::Cancel)
        return false;
    return true;
}

//------------- PUBLIC -------------//
void ListViewControl::setEditable(const bool value)
{
    ui->button_edit->setEnabled(value);
    ui->button_create->setEnabled(value);
    ui->button_delete->setEnabled(value);
}

void ListViewControl::selectFirstElement()
{
    QModelIndex index=model->index(0,0);
    if(index.isValid())
        selection->setCurrentIndex(index,QItemSelectionModel::SelectCurrent);
}



//-------- Getter & Setter ---------//

void ListViewControl::setModel(AbstractListModel *model)
{
    this->model=model;
    ui->listView->setModel(model);
}
void ListViewControl::setSelectionModel(QItemSelectionModel *selection)
{
    this->selection=selection;
    ui->listView->setSelectionModel(selection);
}
