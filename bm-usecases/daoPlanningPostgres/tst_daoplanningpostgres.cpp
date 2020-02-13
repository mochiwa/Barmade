#include <QtTest>
#include <QCoreApplication>

#include "sql/database_manager.h"
#include <memory>
#include <vector>
using namespace std;
class DaoPlanningPostgres : public QObject
{
    Q_OBJECT

public:
    DaoPlanningPostgres();
    ~DaoPlanningPostgres();

private slots:
    void test_create_planning_with_correct_values();
    void test_create_planning_with_end_lower_then_begin();
    void test_get_planning_by_id();
    void test_udpate_existing_planning();
    void test_getPlannings_By_user();
    void test_set_a_dayoff();

};

DaoPlanningPostgres::DaoPlanningPostgres()
{

}

DaoPlanningPostgres::~DaoPlanningPostgres()
{

}



void DaoPlanningPostgres::test_create_planning_with_correct_values()
{
    Planning p;
    QTime begin_time(8, 30, 0);
    QDate end_date(2012, 7, 6);
    QTime end_time(18, 30, 0);

    p.setBegin(QDateTime(QDate(2012, 7, 6),QTime(4,0)));
    p.setEnd(QDateTime(QDate(2012, 7, 6),QTime(5,30)));
    p.setComment("");
    p.setIdOwner(2);//2 is the id of an entity teste
    DatabaseManager::getInstance().planningDao->create(p);

    QVERIFY(p.getId()!=-1);

}
void DaoPlanningPostgres::test_create_planning_with_end_lower_then_begin()
{
    Planning p;
    QTime begin_time(8, 30, 0);
    QDate end_date(2012, 7, 6);
    QTime end_time(18, 30, 0);

    p.setEnd(QDateTime(QDate(2012, 7, 6),QTime(6,0)));
    p.setBegin(QDateTime(QDate(2012, 7, 6),QTime(18,30)));
    p.setComment("");
    p.setIdOwner(2);//2 is the id of an entity teste
    DatabaseManager::getInstance().planningDao->create(p);

    QVERIFY(p.getId()==-1);

}

void DaoPlanningPostgres::test_get_planning_by_id()
{
    Planning p;
    p=DatabaseManager::getInstance().planningDao->getById(1);
    QVERIFY(p.getId()!=-1);
    QVERIFY(p.getIdOwner()==2);
}

void DaoPlanningPostgres::test_udpate_existing_planning()
{
    Planning p;
    Planning copy;
    p=DatabaseManager::getInstance().planningDao->getById(1);
    QVERIFY(p.getId()!=-1);
    p.setComment("un long commentaire !");
    DatabaseManager::getInstance().planningDao->update(p);
    copy=DatabaseManager::getInstance().planningDao->getById(1);
    QVERIFY(p==copy);

}

void DaoPlanningPostgres::test_getPlannings_By_user()
{
    unique_ptr<vector<unique_ptr<Planning>>> list=DatabaseManager::getInstance().planningDao->getPlanningByEmployee(2);
    QVERIFY(list->size()>0);
}
#include <QDebug>
void DaoPlanningPostgres::test_set_a_dayoff()
{
    Planning p;
    Planning copy;
    bool base;
    p=DatabaseManager::getInstance().planningDao->getById(1);
    QVERIFY(p.getId()!=-1);
    base=p.getIsDayOff();
    if(base)
        p.setIsDayOff(false);
    else
        p.setIsDayOff(true);
    DatabaseManager::getInstance().planningDao->update(p);
    copy=DatabaseManager::getInstance().planningDao->getById(1);
    qDebug()<<p.getIsDayOff()<<"---"<<copy.getIsDayOff();
    QVERIFY(copy.getIsDayOff()!=base);
}




QTEST_MAIN(DaoPlanningPostgres)

#include "tst_daoplanningpostgres.moc"
