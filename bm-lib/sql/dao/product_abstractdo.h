#ifndef PRODUCT_ABSTRACTDO_H
#define PRODUCT_ABSTRACTDO_H
#include "abstractdao.h"
#include "entities/product.h"

class ProductAbstractDo : public AbstractDao<Product>
{
public:
    ProductAbstractDo(QSqlDatabase &db):AbstractDao(db){}
    virtual ~ProductAbstractDo();
    virtual std::unique_ptr<std::vector<std::unique_ptr<Product>>> getAll() const=0;
};

#endif // PRODUCT_ABSTRACTDO_H
