#ifndef SUPPLIERBUILDER_H
#define SUPPLIERBUILDER_H

#include "abstractbuilder.h"
#include "entities/supplier.h"
#include "entitybuilder.h"
#include "vector"
#include "memory"
class SupplierBuilder : public AbstractBuilder<Supplier>
{
public:
    static SupplierBuilder getInstance();
    void build(Supplier& e)const;
    void update(Supplier& e)const;
    void load(Supplier& e)const;
    std::unique_ptr<std::vector<std::unique_ptr<Supplier>>> getAll();
protected:
    SupplierBuilder();
};

#endif // SUPPLIERBUILDER_H
