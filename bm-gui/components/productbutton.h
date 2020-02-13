#ifndef PRODUCTBUTTON_H
#define PRODUCTBUTTON_H

#include <QObject>
#include <QPushButton>
#include "entities/product.h"
class ProductButton : public QPushButton
{
    Q_OBJECT
public:
    static ProductButton *make_ProductButton(const QVariant& variant,QWidget *parent=nullptr);
    ProductButton(const Product& product,QWidget *parent=nullptr);
    Product getProduct() const;

private:
    void init();
private:
    Product product;
};

#endif // PRODUCTBUTTON_H
