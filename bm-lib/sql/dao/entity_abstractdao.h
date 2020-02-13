#ifndef ENTITY_ABSTRACTDAO_H
#define ENTITY_ABSTRACTDAO_H

#include "abstractdao.h"
#include "entities/entity.h"

class EntityAbstractDao : public AbstractDao<Entity>
{
public:
    EntityAbstractDao(QSqlDatabase &db):AbstractDao(db){}
    virtual ~EntityAbstractDao();

};

#endif // ENTITY_ABSTRACTDAO_H
