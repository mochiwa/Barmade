#ifndef STOCKCOMPARISON_H
#define STOCKCOMPARISON_H

#include "../abstractcomparison.h"
#include "entities/product.h"
class StockComparison: public AbstractComparison<Product>
{
public:
    StockComparison();

    virtual bool compare(const Product& a,const Product& b)const override; // a > b =true
private:
};

#endif // STOCKCOMPARISON_H
