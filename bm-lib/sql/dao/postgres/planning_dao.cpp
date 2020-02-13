#include "planning_dao.h"
using namespace std;
PlanningDao::PlanningDao(QSqlDatabase &db):
    PlanningAbstractDao (db)
{
    init();
}

void PlanningDao::create(Planning &p) const
{
    QSqlQuery q(db);
    q.prepare("SELECT f_create_planning(:begin,:end,:id_employee,:comment,:dayoff)");
    q.bindValue(":begin",p.getBegin().toString("yyyy-M-d H:mm:ss"));
    q.bindValue(":end",p.getEnd().toString("yyyy-M-d H:mm:ss"));
    q.bindValue(":id_employee",p.getIdOwner());
    q.bindValue(":comment",p.getComment());
    q.bindValue(":dayoff",p.getIsDayOff());
    q.exec();
    if(q.next())
        p.setId(q.value(0).toInt());
}

void PlanningDao::update(const Planning &p) const
{
    QSqlQuery q(db);
    q.prepare("SELECT f_update_planning(:id,:isDelete,:begin,:end,:id_employee,:comment,:isDayOff)");
    q.bindValue(":id",p.getId());
    q.bindValue(":isDelete",p.getIsDelete());
    q.bindValue(":begin",p.getBegin().toString("yyyy-M-d H:mm:ss"));
    q.bindValue(":end",p.getEnd().toString("yyyy-M-d H:mm:ss"));
    q.bindValue(":id_employee",p.getIdOwner());
    q.bindValue(":comment",p.getComment());
    q.bindValue(":isDayOff",p.getIsDayOff());
    q.exec();

}

void PlanningDao::remove(const Planning &p) const
{
    Q_UNUSED(p);
}

Planning PlanningDao::getById(int id) const
{
    Planning p;
    QSqlQuery q(db);
    q.prepare("SELECT * FROM f_get_plannings() WHERE id_planning=:id");
    q.bindValue(":id",id);
    q.exec();
    if(q.next())
    {
        p.setId(q.value("id_planning").toInt());
        p.setIsDelete(q.value("isDelete_planning").toBool());
        p.setBegin(q.value("begin_planning").toDateTime());
        p.setEnd(q.value("end_planning").toDateTime());
        p.setIdOwner(q.value("id_employee").toInt());
        p.setComment(q.value("comment_planning").toString());
        p.setIsDayOff(q.value("isDayOff").toInt());
    }
    return p;
}


std::unique_ptr<std::vector<std::unique_ptr<Planning>>> PlanningDao::getAll() const
{
    QSqlQuery q(db);
    unique_ptr<vector<unique_ptr<Planning>>> list(new vector<unique_ptr<Planning>>);
    q.prepare("SELECT * FROM f_get_plannings_where_deleted()");
    q.exec();
    while(q.next())
    {
        unique_ptr<Planning> p(new Planning());
        p->setId(q.value("id_planning").toInt());
        p->setIsDelete(q.value("isDelete_planning").toBool());
        p->setBegin(q.value("begin_planning").toDateTime());
        p->setEnd(q.value("end_planning").toDateTime());
        p->setIdOwner(q.value("id_employee").toInt());
        p->setComment(q.value("comment_planning").toString());
        p->setIsDayOff(q.value("isDayOff").toInt());
        list->push_back(move(p));
    }
    return list;
}

//a refactorer
std::unique_ptr<std::vector<std::unique_ptr<Planning>>> PlanningDao::getPlanningByEmployee(int idUser) const
{
    QSqlQuery q(db);
    unique_ptr<vector<unique_ptr<Planning>>> list(new vector<unique_ptr<Planning>>);
    q.prepare("SELECT * FROM f_get_plannings_where_deleted() WHERE id_employee=:id");
    q.bindValue(":id",idUser);
    q.exec();
    while(q.next())
    {
        unique_ptr<Planning> p(new Planning());
        p->setId(q.value("id_planning").toInt());
        p->setIsDelete(q.value("isDelete_planning").toBool());
        p->setBegin(q.value("begin_planning").toDateTime());
        p->setEnd(q.value("end_planning").toDateTime());
        p->setIdOwner(q.value("id_employee").toInt());
        p->setComment(q.value("comment_planning").toString());
        p->setIsDayOff(q.value("isDayOff").toInt());
        list->push_back(move(p));
    }
    return list;
}

void PlanningDao::init()
{

}
