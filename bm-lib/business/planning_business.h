#ifndef PLANNING_CONTROLLER_H
#define PLANNING_CONTROLLER_H

#include "../bm-lib_global.h"
#include "models/planning_model.h"
#include <vector>
#include <memory>

typedef std::unique_ptr<std::vector<std::unique_ptr<Planning>>> ArrayPlanning;

class BMLIBSHARED_EXPORT PlanningBusiness
{
public:
    PlanningBusiness(PlanningModel *model);

    bool isPlanningBetween(const Planning& planning,
                           const QDateTime& begin,
                           const QDateTime& end);
    bool isPlanningBetween(const Planning& planning,
                           Qt::DayOfWeek begin,
                           Qt::DayOfWeek end);

    bool appendPlanning(Employee& employee,const Planning& planning);

    bool isPlanningOutdated(Planning const& p,QDate expiry=QDate::currentDate());

    void makeWeekPlanning();

private:
    PlanningModel *model;
    QDate dateToMonday(QDate date);
};
#endif // PLANNING_CONTROLLER_H
