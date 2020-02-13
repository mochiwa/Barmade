#ifndef SUPPLIER_ABSTRACTDAO_H
#define SUPPLIER_ABSTRACTDAO_H


#include "abstractdao.h"
#include "entities/supplier.h"

class SupplierAbstractDao : public AbstractDao<Supplier>
{
public:
    SupplierAbstractDao(QSqlDatabase &db):AbstractDao(db){}
    virtual ~SupplierAbstractDao();
    virtual std::unique_ptr<std::vector<std::unique_ptr<Supplier>>> getAll() const=0;
};

#endif // SUPPLIER_ABSTRACTDAO_H
