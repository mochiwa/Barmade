#include "stockcomparison.h"
#include "business/productbusiness.h"

StockComparison::StockComparison()
{

}

bool StockComparison::compare(const Product &a, const Product &b)const
{
    ProductBusiness business;
    return business.getStockCapacity(a)>business.getStockCapacity(b);
}
