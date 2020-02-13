#ifndef PRODUCTCOMPOSITION_H
#define PRODUCTCOMPOSITION_H

#include "serializers/serializable.h"
#include "capacity.h"

class Ingredient : public Serializable
{
public:
    Ingredient();
    Ingredient(const QVariant& variant);
    Ingredient(int compose,int composed,Capacity qty);

    virtual QVariant toVariant() const;
    virtual void fromVariant(const QVariant &variant);
    bool operator==(const Ingredient& src)const ;
    bool operator!=(const Ingredient& src)const;

    int getIngredient() const;
    void setIngredient(int value);

    int getProduct() const;
    void setProduct(int value);

    Capacity getQuantity() const;
    void setQuantity(Capacity quantity);

    bool isDeleted() const;
    void setDeleted(bool value);

private:
    int idIngredient;
    int idProduct;
    Capacity quantity;
    bool deleted;
};

#endif // PRODUCTCOMPOSITION_H
