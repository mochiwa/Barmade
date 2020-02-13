#ifndef ENTITY_DAO_H
#define ENTITY_DAO_H

#include "../entity_abstractdao.h"

class EntityDao : public EntityAbstractDao
{
public:
    EntityDao(QSqlDatabase &db);

    // AbstractDao interface
public:
    virtual void create(Entity &) const;
    virtual void update(const Entity &) const;
    virtual void remove(const Entity &) const;
    virtual Entity getById(int id) const;
protected:
    virtual void init();
};

#endif // ENTITY_DAO_H
