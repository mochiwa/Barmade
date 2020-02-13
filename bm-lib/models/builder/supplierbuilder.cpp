#include "supplierbuilder.h"
using namespace std;
SupplierBuilder::SupplierBuilder()
{

}

SupplierBuilder SupplierBuilder::getInstance()
{
    SupplierBuilder builder;
    return builder;
}

void SupplierBuilder::build(Supplier &s) const
{
    EntityBuilder builder;
    builder.build(s);

    db.supplierDao->create(s);
}

void SupplierBuilder::update(Supplier &s) const
{
    EntityBuilder builder;
    builder.update(s);

    db.supplierDao->update(s);
}

void SupplierBuilder::load(Supplier &s) const
{
    EntityBuilder builder;

    builder.load(s);
}

unique_ptr<vector<unique_ptr<Supplier>>> SupplierBuilder::getAll()
{
   unique_ptr<vector<unique_ptr<Supplier>>> list=db.supplierDao->getAll();
   for(unsigned int i=0;i<list->size();++i)
        load(*list->at(i));
   return list;
}
