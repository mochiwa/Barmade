#ifndef PRODUCT_DAO_H
#define PRODUCT_DAO_H

#include "../product_abstractdo.h"

class ProductDao : public ProductAbstractDo
{
public:
    ProductDao(QSqlDatabase &db);
    // AbstractDao interface
public:
    virtual void create(Product &) const;
    virtual void update(const Product &) const;
    virtual void remove(const Product &) const;
    virtual Product getById(int id) const;
    virtual std::unique_ptr<std::vector<std::unique_ptr<Product>>> getAll() const;
protected:
    virtual void init();
};

#endif // PRODUCT_DAO_H
