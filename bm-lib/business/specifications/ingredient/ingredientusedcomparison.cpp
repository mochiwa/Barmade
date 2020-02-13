#include "ingredientusedcomparison.h"
#include "business/productbusiness.h"

IngredientUsedComparison::IngredientUsedComparison(const ProductBusiness* business)
{
    this->business=business;
}

bool IngredientUsedComparison::compare(const Ingredient &a, const Ingredient &b) const
{
    Product productA=business->getProduct(a.getIngredient());
    Product productB=business->getProduct(b.getIngredient());

    Capacity stockA=business->getStockCapacity(productA);
    Capacity stockB=business->getStockCapacity(productB);
    return (stockA/a.getQuantity())>(stockB/b.getQuantity());

}
