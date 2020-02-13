#include "planningviewcontrol.h"
#include "ui_planningviewcontrol.h"
#include "ui_tableviewcontrol.h"

PlanningViewControl::PlanningViewControl(QWidget *parent) :
    TableViewControl(parent)//,
    //planningUi(new Ui::PlanningViewControl)
{
    init();
    connect(ui->tableView,&QAbstractItemView::doubleClicked,this,&PlanningViewControl::on_calendarPopup);
    ui->tableView->setItemDelegate(new PlanningDelegate(this));

}

void PlanningViewControl::on_load(int id)
{
    PlanningModel *planningModel=static_cast<PlanningModel*>(model);
    planningModel->setEmployeeId(id);
    ui->tableView->resizeColumnToContents(0);
}

void PlanningViewControl::on_loadAll()
{

}

void PlanningViewControl::on_create()
{
    TableViewControl::on_create();
    Planning p;
    model->setData(selection->currentIndex(),p.toVariant(),AbstractTableModel::Roles::MakeEntity);
}

void PlanningViewControl::on_calendarPopup(const QModelIndex &index)
{
    if(index.column()!=0 || ui->tableView->editTriggers()==QAbstractItemView::NoEditTriggers)
       return ;
    DaySelector *daySelector=new DaySelector();
    Planning p;

    p.fromVariant(model->data(index,AbstractTableModel::Roles::VariantRole));
    if(daySelector->exec())
    {
        p.setBegin(daySelector->getDate());
        p.setEnd(daySelector->getDate());
        model->setData(index,p.toVariant(),AbstractTableModel::Roles::VariantRole);
    }
    delete daySelector;
}

void PlanningViewControl::init()
{
    TableViewControl::init();

}
