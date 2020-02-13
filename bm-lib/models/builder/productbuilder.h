#ifndef PRODUCTBUILDER_H
#define PRODUCTBUILDER_H

#include "abstractbuilder.h"
#include "entities/product.h"
#include <vector>
#include <memory>
class ProductBuilder : public AbstractBuilder<Product>
{
public:
    static ProductBuilder getInstance();
    void build(Product& p)const;
    void update(Product& p)const;
    void load(Product& p)const;
    std::unique_ptr<std::vector<std::unique_ptr<Product>>> getAll();
protected:
    ProductBuilder();
};

#endif // PRODUCTBUILDER_H
