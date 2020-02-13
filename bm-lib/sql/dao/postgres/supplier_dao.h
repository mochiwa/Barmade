#ifndef SUPPLIER_DAO_H
#define SUPPLIER_DAO_H

#include "../supplier_abstractdao.h"
class SupplierDao :public SupplierAbstractDao
{
public:
    SupplierDao(QSqlDatabase &db);

    // AbstractDao interface
public:
    virtual void create(Supplier &) const;
    virtual void update(const Supplier &) const;
    virtual void remove(const Supplier &) const;
    virtual Supplier getById(int id) const;
    virtual std::unique_ptr<std::vector<std::unique_ptr<Supplier>>> getAll() const;

protected:
    virtual void init();
};

#endif // SUPPLIER_DAO_H
