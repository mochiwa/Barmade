#include "city_dao.h"
using namespace postgres;
CityDao::CityDao(QSqlDatabase &db):
    CityAbstractDao (db)
{
    init();
}

void CityDao::create(City &c)const
{
    QSqlQuery q(db);
    q.prepare("SELECT f_create_city(:city,:cp)");
    q.bindValue(":city",c.getName());
    q.bindValue(":cp",c.getCp());
    q.exec();
    if(q.next())
        c.setId(q.value(0).toInt());
}

void CityDao::update(const City &c)const
{
    QSqlQuery q(db);
    q.prepare("SELECT f_update_city(:id,:city,:cp)");
    q.bindValue(":id",c.getId());
    q.bindValue(":city",c.getName());
    q.bindValue(":cp",c.getCp());
    q.exec();
}

void CityDao::remove(const City &c)const
{
    Q_UNUSED(c);
}

City CityDao::getById(int id)const
{
    City c;
    QSqlQuery q(db);
    q.prepare("SELECT * FROM f_get_cities() WHERE id_city=:id");
    q.bindValue(":id",id);
    q.exec();
    if( q.next())
    {
        c.setId(q.value("id_city").toInt());
        c.setName(q.value("name_city").toString());
        c.setCp(q.value("cp_city").toString());
    }
    return c;
}


void CityDao::init()
{

}
