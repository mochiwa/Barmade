#include <QtTest>
#include <QCoreApplication>

#include "entities/employee.h"
#include "models/planning_model.h"
#include "controllers/planning_controller.h"


class planningEmployee : public QObject
{
    Q_OBJECT

public:
    planningEmployee();
    ~planningEmployee();

private slots:
    void test_as_an_manager_i_append_planning_to_employee();
    void test_as_an_employee_i_want_to_see_my_planning();

private:
    //planningController controller;
    PlanningModel plannings;
    TypeEmployee manager;
    TypeEmployee waiter;
};

planningEmployee::planningEmployee(): plannings(this)
{
    manager.setName("manager");
    waiter.setName("waiter");

}

planningEmployee::~planningEmployee()
{
    QDate begin_d(2012, 7, 6);
    QTime begin_t(8, 30, 0);
    QDate end_d(2012, 7, 6);
    QTime end_t(18, 30, 0);
    plannings.append(Planning(1,QDateTime(begin_d,begin_t),QDateTime(end_d,end_t)));
    begin_d=QDate(2017, 4, 10);
    begin_t=QTime(9, 0, 0);
    end_d=QDate(2017, 4, 10);
    end_t=QTime(16, 30, 0);
    plannings.append(Planning(2,QDateTime(begin_d,begin_t),QDateTime(end_d,end_t)));
}

void planningEmployee::test_as_an_manager_i_append_planning_to_employee()
{
//Given I'm a "<employee>"
    Employee manager;
    manager.setId(1);
    manager.setType(this->manager);
//And I want to append a "<planning>" to an "<employee>"

    QDate begin_d(2019, 4, 8);
    QTime begin_t(8, 30, 0);
    QDate end_d(2019, 4, 10);
    QTime end_t(18, 30, 0);
    Planning planning(3,QDateTime(begin_d,begin_t),QDateTime(end_d,end_t));
//And I have the "<right>" to do that
    //noementedt impl
//When I select the "<employee>"
    Employee waiter;
    waiter.setId(1);
    waiter.setType(this->waiter);
//And the day of the "<planning>" is between monday and saturday
    QCOMPARE(controller.isPlanningBetween(planning,Qt::DayOfWeek::Monday,Qt::DayOfWeek::Saturday),true);
    controller.appendPlanning(waiter,planning);
//Then the employee have a new planning
    QCOMPARE(waiter.getPlannings().at(0)->getId(),planning.getId());
}

void planningEmployee::test_as_an_employee_i_want_to_see_my_planning()
{
    planningController controller;

//Given I'm a "<employee>"
    Employee waiter;
    waiter.setId(1);
    waiter.setType(this->waiter);
//And I want to see my "<planning>"
    QDate date(2012, 7, 6);
    QTime time(8, 30, 0);
    Planning planning(1,QDateTime(date,time),QDateTime(date,time));
    Planning planning2(1,QDateTime(date,time),QDateTime(date,time));
//When i select plannings menu
    controller.appendPlanning(waiter,planning);
    controller.appendPlanning(waiter,planning2);
//Then i can only see my planning
    QCOMPARE(waiter.getPlannings().size(),2);
}


QTEST_MAIN(planningEmployee)

#include "tst_planningemployee.moc"
