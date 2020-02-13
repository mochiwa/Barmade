#include "entitybuilder.h"

EntityBuilder::EntityBuilder(): AbstractBuilder<Entity> ()
{

}
void EntityBuilder::build(Entity &e)const
{
    City city=e.getCity();
    Street street=e.getStreet();

    db.cityDao->create(city);
    street.setId_city(city.getId());
    db.streetDao->create(street);
    e.setCity(city);
    e.setStreet(street);
    db.entityDao->create(e);
    load(e);
}

void EntityBuilder::update(Entity &e)const
{
    City city=e.getCity();
    Street street=e.getStreet();

    db.cityDao->create(city);
    street.setId_city(city.getId());
    db.streetDao->create(street);
    e.setStreet(street);
    e.setCity(city);
    db.entityDao->update(e);
}

void EntityBuilder::load(Entity &e) const
{
    City city;
    Street street;

    e=db.entityDao->getById(e.getId());
    street=db.streetDao->getById(e.getStreet().getId());
    city=db.cityDao->getById(street.getId_city());

    e.setStreet(street);
    e.setCity(city);
}
