#include "stocksearch.h"

stockSearch::stockSearch()
{

}

Product const& stockSearch::recursiveSearch(const std::vector<Product>&products, int size, int minPosition, AbstractComparison<Product> &comparison) const
{
    Product current;
    Product compare;
    if(size>-1)
    {
        current=products.at(size);
        compare=products.at(minPosition);
        if(!comparison.compare(current,compare))
            minPosition=size;
        return recursiveSearch(products,size-1,minPosition,comparison);
    }
    return products.at(minPosition);
}

Product const& stockSearch::search(const std::vector<Product>& products, AbstractComparison<Product> &comparison)const
{
    return  recursiveSearch(products,products.size()-1,0,comparison);
}
