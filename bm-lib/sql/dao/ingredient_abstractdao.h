#ifndef COMPOSITIONPRODUCT_ABSTRACTDAO_H
#define COMPOSITIONPRODUCT_ABSTRACTDAO_H

#include "abstractdao.h"
#include "valueObjects/ingredient.h"

class IngredientAbstractDao : public AbstractDao<Ingredient>
{
public:
    IngredientAbstractDao(QSqlDatabase &db):AbstractDao(db){}
    virtual ~IngredientAbstractDao();

    //virtual CompositionProduct getByBothId(int compose,int composed)const=0;
    virtual std::vector<Ingredient> getIngredientsOf(int owner)const=0;
    //virtual std::unique_ptr<std::vector<std::unique_ptr<CompositionProduct>>> getProductByIngredient(int idIngredient) const=0;
    virtual void removeAllFrom(const int idProduct)const=0;

};

#endif // COMPOSITIONPRODUCT_ABSTRACTDAO_H
