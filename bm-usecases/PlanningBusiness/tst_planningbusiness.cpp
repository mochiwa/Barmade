#include <QtTest>
#include <QCoreApplication>

#include "sql/database_manager.h"
#include "models/planning_model.h"
#include "business/planning_business.h"

class PlanningBusinessTest : public QObject
{
    Q_OBJECT

public:
    PlanningBusinessTest();
    ~PlanningBusinessTest();

private slots:
    void test_get_last_planning();
    void test_make_week_planning();
    void test_planning_is_outdated();
    void test_if_the_last_planning_is_out_of_date_make_news();

};

PlanningBusinessTest::PlanningBusinessTest()
{

}

PlanningBusinessTest::~PlanningBusinessTest()
{

}

void PlanningBusinessTest::test_make_week_planning()
{
    PlanningModel *model=new PlanningModel(this);
    PlanningBusiness business(model);
    model->setEmployeeId(2);

    business.makeWeekPlanning();
}

void PlanningBusinessTest::test_get_last_planning()
{
    PlanningModel *model=new PlanningModel(this);
    model->setEmployeeId(2);
    Planning last=model->getLastPlanning();
    QVERIFY(!last.getBegin().toString("dddd").compare("Sunday"));
}


void PlanningBusinessTest::test_planning_is_outdated()
{
    PlanningModel *model=new PlanningModel(this);
    PlanningBusiness business(model);
    model->setEmployeeId(139);
    Planning last=model->getLastPlanning();
    QVERIFY(business.isPlanningOutdated(last));
}

void PlanningBusinessTest::test_if_the_last_planning_is_out_of_date_make_news()
{
    //GIVEN : i'm an Planning master
   /* PlanningModel *model=new PlanningModel(this);
    PlanningBusiness *business=new PlanningBusiness(model);
    Planning last;
    //WHEN my planning is loaded
    model->setEmployeeId(139);
    //AND my last planning is less than the current date
    last=model->getLastPlanning();
    if(business->isPlanningOutdated(last,QDate::currentDate()))
    {}
    //THEN the 7 last planning will be deleted
     model->removeRows(0,6,QModelIndex());
    //AND 7 new plannings will be created
    /* business->makeNewPlannings();
     QCOMPARE(business.isPlanningOutdate(),false);
    delete business;*/
}


QTEST_MAIN(PlanningBusinessTest)

#include "tst_planningbusiness.moc"
