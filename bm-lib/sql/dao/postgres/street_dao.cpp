#include "street_dao.h"

StreetDao::StreetDao(QSqlDatabase &db):
    StreetAbstractDao (db)
{
    init();
}

void StreetDao::create(Street &s) const
{
    QSqlQuery q(db);
    q.prepare("SELECT f_create_street(:name,:number,:id_city)");
    q.bindValue(":name",s.getName());
    q.bindValue(":number",s.getNumber());
    q.bindValue(":id_city",s.getId_city());
    q.exec();
    if(q.next())
        s.setId(q.value(0).toInt());

}
void StreetDao::update(const Street &s) const
{
    QSqlQuery q(db);
    q.prepare("SELECT f_update_street(:id,:name,:number,:id_city)");
    q.bindValue(":id",s.getId());
    q.bindValue(":name",s.getName());
    q.bindValue(":number",s.getNumber());
    q.bindValue(":id_city",s.getId_city());
    q.exec();
}
void StreetDao::remove(const Street &s) const
{
    Q_UNUSED(s);
}
Street StreetDao::getById(int id) const
{
    Street s;
    QSqlQuery q(db);
    q.prepare("SELECT * FROM f_get_streets() WHERE id_street=:id");
    q.bindValue(":id",id);
    q.exec();
    if(q.next())
    {
        s.setId(q.value("id_street").toInt());
        s.setName(q.value("name_street").toString());
        s.setNumber(q.value("number_street").toString());
        s.setId_city(q.value("id_city").toInt());
    }
    return s;
}

Street StreetDao::getStreet_by_idEntity(int id_entity)
{
    QSqlQuery q(db);
    q.prepare("SELECT f_getStreetId_by_idEntity(:id)");
    q.bindValue(":id",id_entity);
    q.exec();
    if(q.next())
        return getById(q.value("id_street").toUInt());
    return Street();
}

// protected
void StreetDao::init()
{

}
