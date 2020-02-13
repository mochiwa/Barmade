#include "tableviewcontrol.h"
#include "ui_tableviewcontrol.h"

TableViewControl::TableViewControl(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TableViewControl)
{
    ui->setupUi(this);

    connect(ui->button_append,SIGNAL(clicked()),this,SLOT(on_create()));
    connect(ui->button_remove,SIGNAL(clicked()),this,SLOT(on_remove()));
}

TableViewControl::~TableViewControl()
{
    delete ui;
}

//------------- SLOTS -------------//
void TableViewControl::on_create()
{
    if(!model)
        return;
    QVariant variant;
    QModelIndex index=model->append(variant);
    ui->tableView->setCurrentIndex(index);
}
void TableViewControl::on_remove()
{
    QModelIndex index=selection->currentIndex();
    if(!index.isValid())
        return;
    if(model->data(selection->currentIndex()).toString().compare(""))
        if(!confirmSuppresionBox())
            return;

    model->setData(index,true,AbstractTableModel::Roles::DeleteRole);
    model->removeRows(index.row(),1,QModelIndex());
    selection->reset();
}
//------------- PRIVATE -------------//
bool TableViewControl::confirmSuppresionBox()
{
    QMessageBox confirmBox(this);
    confirmBox.setText("Do you want to erase "+model->data(selection->currentIndex(),Qt::DisplayRole).toString()+" ?");
    confirmBox.setStandardButtons(QMessageBox::Cancel |QMessageBox::Yes);
    if(confirmBox.exec()==QMessageBox::Cancel)
        return false;
    return true;
}
void TableViewControl::init()
{
    model=nullptr;
    selection=nullptr;
    initStyleSheet();
}

void TableViewControl::initStyleSheet()
{
    QFile f(":/css/table_view.css");
    f.open(QFile::ReadOnly);
    ui->frame->setStyleSheet(QLatin1String(f.readAll()));
    f.close();
}
//------------- PUBLIC -------------//
void TableViewControl::setEditable(const bool value)
{
    ui->button_append->setEnabled(value);
    ui->button_remove->setEnabled(value);
    //ui->layout_button->setEnabled(value);
    ui->frame_button->setVisible(value);
    if(!value)
        ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    else
        ui->tableView->setEditTriggers(QAbstractItemView::DoubleClicked);
}

//-------- Getter & Setter ---------//
void TableViewControl::setModel(AbstractTableModel *model)
{
    this->model=model;
    ui->tableView->setModel(model);//yes or no ?
}

void TableViewControl::setSelection(QItemSelectionModel *selection)
{
    this->selection=selection;
    ui->tableView->setSelectionModel(selection);
}
