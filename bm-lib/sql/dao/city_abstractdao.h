#ifndef CITY_ABSTRACTDAO_H
#define CITY_ABSTRACTDAO_H

#include "abstractdao.h"
#include "entities/city.h"

class CityAbstractDao : public AbstractDao<City>
{
public:
    CityAbstractDao(QSqlDatabase &db):AbstractDao(db){}
    virtual ~CityAbstractDao();

};



#endif // CITY_ABSTRACTDAO_H
