#include "planning_business.h"

PlanningBusiness::PlanningBusiness(PlanningModel *model)
{
    this->model=model;
}


bool PlanningBusiness::isPlanningBetween(const Planning& planning,const QDateTime& begin, const QDateTime& end)
{
    if (planning.getBegin()>=begin && planning.getEnd()<=end)
        return true;
    return false;
}

bool PlanningBusiness::isPlanningBetween(const Planning &planning, Qt::DayOfWeek begin, Qt::DayOfWeek end)
{
    int planning_begin=planning.getBegin().date().dayOfWeek();
    int planning_end=planning.getEnd().date().dayOfWeek();

    if(planning_begin>planning_end)
        return false;
    else if(planning_end < begin || planning_end > end)
        return false;
    else if(planning_begin<begin)
        return false;
    else
        return true;
}

bool PlanningBusiness::isPlanningOutdated(const Planning &p,QDate expiry)
{
    if(p.getEnd().date()<expiry)
        return true;
    return false;
}

QDate PlanningBusiness::dateToMonday(QDate date)
{
    if(date.dayOfWeek()==1)
        return date;
    return dateToMonday(date.addDays(-1));
}


void PlanningBusiness::makeWeekPlanning()
{
    Planning mondayPlanning;
    QDateTime beginDate;

    beginDate.setDate(dateToMonday(QDate::currentDate()));
    mondayPlanning.setBegin(beginDate);
    mondayPlanning.setEnd(beginDate);
}

