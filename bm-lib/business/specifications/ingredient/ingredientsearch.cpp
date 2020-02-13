#include "ingredientsearch.h"

IngredientSearch::IngredientSearch()
{

}

Ingredient const& IngredientSearch::recursiveSearch(const std::vector<Ingredient> &ingredients, int size, int minPosition, AbstractComparison<Ingredient> &comparison) const
{
    Ingredient current;
    Ingredient compare;
    if(size>-1)
    {
        current=ingredients.at(size);
        compare=ingredients.at(minPosition);
        if(!comparison.compare(current,compare))
            minPosition=size;
        return recursiveSearch(ingredients,size-1,minPosition,comparison);
    }
    return ingredients.at(minPosition);
}

Ingredient const& IngredientSearch::search(const std::vector<Ingredient> &ingredients, AbstractComparison<Ingredient> &comparison) const
{
    return recursiveSearch(ingredients,ingredients.size()-1,0,comparison);
}
