#include "compositionorder.h"

CompositionOrder::CompositionOrder()
{
    setIdOrder(0);
    setIdProduct(0);
    setQuantity(0);
}

CompositionOrder::CompositionOrder(const QVariant &variant)
{
    fromVariant(variant);
}

CompositionOrder::CompositionOrder(int idOrder, int idProduct, int quantity)
{
    setIdOrder(idOrder);
    setIdProduct(idProduct);
    setQuantity(quantity);
}

bool CompositionOrder::operator==(const CompositionOrder &c)
{
    if(idOrder!=c.idOrder)
        return false;
    if(idProduct!=c.idProduct)
        return false;
    if(quantity!=c.quantity)
        return false;
    return true;
}

QVariant CompositionOrder::toVariant() const
{
    QVariantMap m;
    m.insert("idOrder",getIdOrder());
    m.insert("idProduct",getIdProduct());
    m.insert("quantity",getQuantity());
    return m;
}

void CompositionOrder::fromVariant(const QVariant &variant)
{
    QVariantMap m =variant.toMap();
    setIdOrder(m.value("idOrder").toInt());
    setIdProduct(m.value("idProduct").toInt());
    setQuantity(m.value("quantity").toInt());
}

int CompositionOrder::getIdOrder() const
{
    return idOrder;
}

void CompositionOrder::setIdOrder(int value)
{
    idOrder = value;
}

int CompositionOrder::getIdProduct() const
{
    return idProduct;
}

void CompositionOrder::setIdProduct(int value)
{
    idProduct = value;
}

int CompositionOrder::getQuantity() const
{
    return quantity;
}

void CompositionOrder::setQuantity(int value)
{
    quantity = value;
}
