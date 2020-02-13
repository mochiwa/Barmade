#ifndef CITY_DAOPOSTGRES_H
#define CITY_DAOPOSTGRES_H

#include "../city_abstractdao.h"
namespace sqlite {


class CityDaoPostgres : public CityAbstractDao
{
public:
    CityDaoPostgres(QSqlDatabase &db);

    // AbstractDao interface
public:
    virtual City getById(unsigned int id) const;
    virtual std::unique_ptr<std::vector<std::unique_ptr<City> > > getAll() const;

protected:
    virtual void init();

    // CityAbstractDao interface
public:
    virtual void create(City &) const;
    virtual void update(City &) const;
    virtual void remove(City &) const;
};
}

#endif // CITY_DAOPOSTGRES_H
