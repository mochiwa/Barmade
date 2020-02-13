#ifndef CITY_DAOPOSTGRES_H
#define CITY_DAOPOSTGRES_H

#include "../city_abstractdao.h"
namespace postgres {


class CityDao :public CityAbstractDao
{
public:
    CityDao(QSqlDatabase &db);

    // AbstractDao interface
    void create(City &)const;
    void update(const City &)const;
    void remove(const City &)const;
    City getById(int id)const;

protected:
    void init();
};
}






#endif // CITY_DAOPOSTGRES_H
