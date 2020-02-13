#ifndef COMPOSITIONPRODUCT_DAO_H
#define COMPOSITIONPRODUCT_DAO_H

#include "../ingredient_abstractdao.h"
class IngredientDao : public IngredientAbstractDao
{
public:
    IngredientDao(QSqlDatabase &db);
    virtual ~ IngredientDao();
    virtual void create(Ingredient &)const;
    virtual void update(const Ingredient &)const;
    virtual void remove(const Ingredient &)const;
    Ingredient getById(int id)const;
    virtual std::vector<Ingredient> getIngredientsOf(int owner)const;
    virtual void removeAllFrom(const int idProduct)const;
protected:
    void init();
};

#endif // COMPOSITIONPRODUCT_DAO_H
