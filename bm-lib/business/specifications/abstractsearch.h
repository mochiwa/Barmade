#ifndef ABSTRACTSEARCH_H
#define ABSTRACTSEARCH_H

#include <vector>
#include "abstractcomparison.h"
template <class T>
class AbstractSearch
{
public:
    AbstractSearch(){}
    virtual ~AbstractSearch(){}

    virtual T const& search(const std::vector<T>& objects,AbstractComparison<T>&)const=0;
};

#endif // ABSTRACTSEARCH_H
