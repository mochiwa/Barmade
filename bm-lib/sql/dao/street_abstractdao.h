#ifndef STREET_ABSTRACTDAO_H
#define STREET_ABSTRACTDAO_H

#include "abstractdao.h"
#include "entities/street.h"

class StreetAbstractDao  : public AbstractDao<Street>
{
public:
    StreetAbstractDao(QSqlDatabase &db):AbstractDao(db){}
    virtual ~StreetAbstractDao();

    virtual Street getStreet_by_idEntity(int id_entity)=0;
};

#endif // STREET_ABSTRACTDAO_H
