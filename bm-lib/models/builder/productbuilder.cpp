#include "productbuilder.h"

using namespace std;
ProductBuilder::ProductBuilder()
{

}


ProductBuilder ProductBuilder::getInstance()
{
    ProductBuilder builder;
    return builder;
}

void ProductBuilder::build(Product& p)const
{
    vector<Ingredient> ingredients=p.getIngredients();
    db.productDao->create(p);
    for(auto& i:ingredients)
    {
        i.setProduct(p.getId());
        db.ingredientDao->create(i);
    }
    p.setIngredients(ingredients);
}

void ProductBuilder::update(Product& p)const
{
    vector<Ingredient> ingredients=p.getIngredients();
    db.productDao->update(p);
    db.ingredientDao->removeAllFrom(p.getId());
    for(auto& i:ingredients)
        db.ingredientDao->update(i);
}

void ProductBuilder::load(Product& p)const
{
    vector<Ingredient> ingredients=db.ingredientDao->getIngredientsOf(p.getId());
    p.setIngredients(ingredients);
}

std::unique_ptr<std::vector<std::unique_ptr<Product>>> ProductBuilder::getAll()
{
    unique_ptr<vector<unique_ptr<Product>>> products=db.productDao->getAll();
    for(unsigned int i=0;i<products->size();++i)
        load(*products->at(i));
    return products;
}
