#ifndef INGREDIENTUSEDCOMPARISON_H
#define INGREDIENTUSEDCOMPARISON_H

#include "../abstractcomparison.h"
#include "entities/product.h"

class ProductBusiness;

class IngredientUsedComparison : public AbstractComparison<Ingredient>
{
public:
    IngredientUsedComparison(const ProductBusiness* business);

    virtual bool compare(const Ingredient& a,const Ingredient& b)const override; // a > b =true

private:
    const ProductBusiness *business;
};

#endif // INGREDIENTUSEDCOMPARISON_H
