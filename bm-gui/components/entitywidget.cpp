#include "entitywidget.h"
#include "ui_entitywidget.h"

EntityWidget::EntityWidget(QWidget *parent):
    QWidget (parent),
    ui(new Ui::EntityWidget)
{
    ui->setupUi(this);
    init();

    connect(ui->button_validate,SIGNAL(clicked()),this,SLOT(on_save()));
    connect(ui->button_cancel,SIGNAL(clicked()),this,SLOT(on_cancel()));
}

EntityWidget::~EntityWidget()
{
   delete ui;
}

//------------- SLOTS -------------//
void EntityWidget::on_load()
{
    if(selection->currentIndex().isValid())
        fillWidget();

    setReadableOnly(true);
    showValidationButtons(false);
    emit entity_presentation();
}

void EntityWidget::on_save()
{
    QVariant variant=model->data(selection->currentIndex(),AbstractListModel::Roles::VariantRole);
    fillEntity(variant);
    if(model->data(selection->currentIndex(),AbstractListModel::Roles::IdRole).toInt()==0)
        model->setData(selection->currentIndex(),variant,AbstractListModel::Roles::MakeEntity);
    else
        model->setData(selection->currentIndex(),variant,AbstractListModel::Roles::VariantRole);
    emit entity_editingFinsih();
}

void EntityWidget::on_edit()
{
    if(!selection->currentIndex().isValid())
        return;

    setReadableOnly(false);
    showValidationButtons(true);
    setProperty(Property::on_edit,true);
}

void EntityWidget::on_cancel()
{
    if(model->data(selection->currentIndex(),AbstractListModel::IdRole)<=0)
        model->removeRows(selection->currentIndex().row(),1,QModelIndex());
    selection->setCurrentIndex(selection->currentIndex(),QItemSelectionModel::SelectCurrent);
    on_load();
    setProperty(Property::on_edit,false);
    emit entity_editingFinsih();
}

void EntityWidget::check_lineEdit_fields()
{
    QLineEdit *line=static_cast<QLineEdit*>(QObject::sender());
   if(isPropertyActived(Property::on_edit)==false)
       return;

    ui->button_validate->setEnabled(false);
    if(!line->hasAcceptableInput())
    {
        line->setStyleSheet("border:1px solid red");
        return;
    }
    else
         line->setStyleSheet("border:none");

    ui->button_validate->setEnabled(true);
}
//------------- PROTECTED -------------//
void EntityWidget::init()
{
    model=nullptr;
    selection=nullptr;
    setProperty(Property::on_edit,false);
    showValidationButtons(false);
}

void EntityWidget::updatStyleSheet()
{
    QFile f(":/css/entity_widget.css");
    f.open(QFile::ReadOnly);
    this->setStyleSheet(QLatin1String(f.readAll()));
    f.close();
    if(cssFilename=="")
        return;

    f.setFileName(cssFilename);
    f.open(QFile::ReadOnly);
    ui->frame_form->setStyleSheet(QLatin1String(f.readAll()));
    f.close();
}

void EntityWidget::setProperty(EntityWidget::Property property, bool value)
{
    switch (property) {
    case Property::on_edit:
        ui->frame_form->setProperty("on_edit",value);
    }
   updatStyleSheet();
   ui->frame_form->style()->unpolish(ui->frame_form);
   ui->frame_form->style()->polish(ui->frame_form);
}

bool EntityWidget::isPropertyActived(EntityWidget::Property property)
{
    switch (property) {
    case Property::on_edit:
        return ui->frame_form->property("on_edit").toBool();
    }
    return false;
}

void EntityWidget::showValidationButtons(bool value)
{
    ui->widgetButtons->setVisible(value);
}

void EntityWidget::setReadableOnly(bool value)
{
    foreach(auto* line,lineEdits)
        line->setReadOnly(value);
}
//-------- Getter & Setter ---------//
void EntityWidget::setModel(AbstractListModel *model)
{
    this->model=model;
    connect(model,&QAbstractItemModel::dataChanged,[this] (const QModelIndex &topleft)
    {
       if(topleft==selection->currentIndex())
           on_load();
    });
}

void EntityWidget::setSelectionModel(QItemSelectionModel *selection)
{
    this->selection=selection;
    connect(selection,&QItemSelectionModel::selectionChanged,[this](const QItemSelection &selected)
    {
        if(selected.isEmpty())
            return;
        on_load();
    });
}
