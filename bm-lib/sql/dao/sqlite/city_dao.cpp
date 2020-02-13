#include "../sqlite/city_dao.h"

using namespace sqlite;
sqlite::CityDaoPostgres::CityDaoPostgres(QSqlDatabase &db):
    CityAbstractDao (db)
{
    init();
}

void CityDaoPostgres::create(City &c) const
{
   QSqlQuery q(db);
   q.prepare("INSERT INTO cities(name_city,cp_city)VALUES(:name,:cp)");
   q.bindValue(":city",c.getName());
   q.bindValue(":cp",c.getCp());
   q.exec();
   c.setId(q.value(0).toInt());
}

void CityDaoPostgres::update(City &c) const
{
    QSqlQuery q(db);
    q.prepare("UPDATE cities SET name_city=v_city, cp_city=v_cp WHERE id_city=:id");
    q.bindValue(":id",c.getId());
    q.exec();
}

void CityDaoPostgres::remove(City &c) const
{
    QSqlQuery q(db);
    q.prepare("DELETE FROM cities WHERE id_city=:id");
    q.bindValue(":id",c.getId());
    q.exec();
}

City CityDaoPostgres::getById(unsigned int id) const
{
    City c;
    QSqlQuery q(db);
    q.prepare("SELECT * from cities WHERE id_city=:id");
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

std::unique_ptr<std::vector<std::unique_ptr<City> > > CityDaoPostgres::getAll() const
{
    return  nullptr;
}

void CityDaoPostgres::init()
{
    if(!db.contains("cities"))
    {
        QSqlQuery q(db);
        q.exec("CREATE TABLE cities( \
               id_city      INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT , \
               name_city    TEXT NOT NULL , \
               cp_city      TEXT NOT NULL\
           );");
    }
}
