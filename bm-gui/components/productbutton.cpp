#include "productbutton.h"

ProductButton *ProductButton::make_ProductButton(const QVariant &variant,QWidget *parent)
{
    Product p;
    p.fromVariant(variant);
    return new ProductButton(p,parent);
}

ProductButton::ProductButton(const Product& product, QWidget *parent):
    QPushButton (parent)
{
    this->product=product;
    init();
}

void ProductButton::init()
{
    setText(product.getName());
    setMaximumSize(200,100);
    setMinimumSize(100,100);
}

Product ProductButton::getProduct() const
{
    return product;
}
