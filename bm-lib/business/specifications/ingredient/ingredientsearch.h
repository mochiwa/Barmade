#ifndef INGREDIENTSEARCH_H
#define INGREDIENTSEARCH_H

#include "../abstractsearch.h"
#include "entities/product.h"

class IngredientSearch : public AbstractSearch<Ingredient>
{
public:
    IngredientSearch();
    Ingredient const& recursiveSearch(const std::vector<Ingredient>& ingredient, int size, int minPosition, AbstractComparison<Ingredient> &comparison) const;


    virtual Ingredient const& search(const std::vector<Ingredient>& objects,AbstractComparison<Ingredient>&)const override;


};

#endif // INGREDIENTSEARCH_H
