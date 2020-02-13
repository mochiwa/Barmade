#ifndef ENTITYBUILDER_H
#define ENTITYBUILDER_H

#include "abstractbuilder.h"
#include "entities/entity.h"
class EntityBuilder : public AbstractBuilder<Entity>
{
public:
    EntityBuilder();

    void build(Entity& e)const;
    void update(Entity& e)const;
    void load(Entity& e)const;
};

#endif // ENTITYBUILDER_H
