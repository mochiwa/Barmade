#ifndef COMPOSITIONORDER_H
#define COMPOSITIONORDER_H

#include "serializers/serializable.h"
class CompositionOrder : public Serializable
{
public:
    CompositionOrder();
    CompositionOrder(const QVariant& variant);
    CompositionOrder(int idOrder,int idProduct,int quantity);
    bool operator==(const CompositionOrder& c);

    virtual QVariant toVariant() const;
    virtual void fromVariant(const QVariant &variant);

    int getIdOrder() const;
    void setIdOrder(int value);

    int getIdProduct() const;
    void setIdProduct(int value);

    int getQuantity() const;
    void setQuantity(int value);

private:
    int idOrder;
    int idProduct;
    int quantity;

};



#endif // COMPOSITIONORDER_H
