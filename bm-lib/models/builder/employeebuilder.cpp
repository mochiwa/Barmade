#include "employeebuilder.h"

using namespace std;
EmployeeBuilder::EmployeeBuilder()
{

}

EmployeeBuilder EmployeeBuilder::getInstance()
{
    EmployeeBuilder builder;
    return builder;
}

void EmployeeBuilder::build(Employee &e) const
{
    TypeEmployee type=e.getType();
    EntityBuilder builder;
    builder.build(e);

    db.typeEmployeeDao->create(type);
    e.setType(type);
    db.employeeDao->create(e);
}

void EmployeeBuilder::update(Employee &e) const
{
    TypeEmployee type=e.getType();
    EntityBuilder builder;
    builder.update(e);

    db.typeEmployeeDao->create(type);
    e.setType(type);
    db.employeeDao->update(e);
}

void EmployeeBuilder::load(Employee &e) const
{
    TypeEmployee type;
    EntityBuilder builder;

    builder.load(e);
    type=db.typeEmployeeDao->getById(e.getType().getId());
    e.setType(type);
}
unique_ptr<vector<unique_ptr<Employee>>> EmployeeBuilder::getAll()
{
   unique_ptr<vector<unique_ptr<Employee>>> list=db.employeeDao->getAll();
   for(unsigned int i=0;i<list->size();++i)
        load(*list->at(i));
   return list;
}
