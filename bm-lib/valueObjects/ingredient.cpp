#include "ingredient.h"

Ingredient::Ingredient()
{
    idProduct=0;
    idIngredient=0;
    quantity=0;
    deleted=false;
}

Ingredient::Ingredient(const QVariant &variant)
{
    fromVariant(variant);
}

Ingredient::Ingredient(int compose, int composed, Capacity qty)
{
    setProduct(compose);
    setIngredient(composed);
    setQuantity(qty);
}

bool Ingredient::operator==(const Ingredient &src)const
{
    if(idProduct!=src.getProduct())
        return false;
    if(idIngredient!=src.getIngredient())
        return false;
    if(quantity!=src.getQuantity())
        return false;
    return true;
}

bool Ingredient::operator!=(const Ingredient &src) const
{
    return !(*this==src);
}

QVariant Ingredient::toVariant() const
{
    QVariantMap m;
    m.insert("id_product",getProduct());
    m.insert("id_ingredient",getIngredient());
    m.insert("quantity",getQuantity().toVariant());
    m.insert("deleted",isDeleted());
    return m;
}

void Ingredient::fromVariant(const QVariant &variant)
{
    QVariantMap m =variant.toMap();
    setProduct(m.value("id_product").toInt());
    setIngredient(m.value("id_ingredient").toInt());
    quantity.fromVariant(m.value("quantity"));
    setDeleted(m.value("deleted").toBool());
}

Capacity Ingredient::getQuantity() const
{
    return quantity;
}

void Ingredient::setQuantity(Capacity value)
{
    quantity= value;
}

bool Ingredient::isDeleted() const
{
    return deleted;
}

void Ingredient::setDeleted(bool value)
{
    deleted = value;
}


int Ingredient::getProduct() const
{
    return idProduct;
}

void Ingredient::setProduct(int value)
{
    idProduct = value;
}

int Ingredient::getIngredient() const
{
    return idIngredient;
}

void Ingredient::setIngredient(int value)
{
    idIngredient = value;
}
