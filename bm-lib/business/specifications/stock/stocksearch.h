#ifndef STOCKSEARCH_H
#define STOCKSEARCH_H

#include "entities/product.h"
#include "../abstractsearch.h"

class stockSearch : public AbstractSearch<Product>
{
public:
    stockSearch();

    Product const& recursiveSearch(const std::vector<Product> &, int size, int minPosition, AbstractComparison<Product>& comparison) const;

    virtual Product const& search(const std::vector<Product>& products,AbstractComparison<Product>& comparison)const override;
};

#endif // STOCKSEARCH_H
