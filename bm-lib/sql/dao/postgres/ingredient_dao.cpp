#include "ingredient_dao.h"

using namespace std;
IngredientDao::IngredientDao(QSqlDatabase &db):
    IngredientAbstractDao(db)
{

}
IngredientDao::~IngredientDao()
{
}

void IngredientDao::create(Ingredient &c)const
{
    QSqlQuery q(db);
    q.prepare("SELECT f_append_ingredient_to_product(:product,:ingredient,:qty)");
    q.bindValue(":product",c.getProduct());
    q.bindValue(":ingredient",c.getIngredient());
    q.bindValue(":qty",c.getQuantity().getValue());
    q.exec();
}

void IngredientDao::update(const Ingredient &c)const
{
    QSqlQuery q(db);
    q.prepare("SELECT f_update_composition_of_product(:product,:ingredient,:qty)");
    q.bindValue(":product",c.getProduct());
    q.bindValue(":ingredient",c.getIngredient());
    q.bindValue(":qty",c.getQuantity().getValue());
    q.exec();
}

void IngredientDao::remove(const Ingredient &c)const
{
    QSqlQuery q(db);
    q.prepare("SELECT f_delete_composition(:product,:ingredient)");
    q.bindValue(":product",c.getProduct());
    q.bindValue(":ingredient",c.getIngredient());
    q.exec();
}


std::vector<Ingredient> IngredientDao::getIngredientsOf(int owner) const
{
    QSqlQuery q(db);
    std::vector<Ingredient> list;
    q.prepare("SELECT * FROM f_get_ingredient_of(:product)");
    q.bindValue(":product",owner);
    q.exec();
    while(q.next())
    {
        Ingredient i;
        i.setProduct(q.value("id_product").toInt());
        i.setIngredient(q.value("id_ingredient").toInt());
        i.setQuantity(q.value("quantity_used").toFloat());
        list.push_back(move(i));
    }
    return list;
}

void IngredientDao::removeAllFrom(const int idProduct) const
{
    QSqlQuery q(db);
    q.prepare("SELECT f_delete_all_from(:id)");
    q.bindValue(":id",idProduct);
    q.exec();
}
void IngredientDao::init()
{

}

Ingredient IngredientDao::getById(int id)const
{
    Q_UNUSED(id);
    return Ingredient();
}
