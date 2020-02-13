#ifndef PRODUCT_MODEL_H
#define PRODUCT_MODEL_H

#include "abstractlistmodel.h"
#include "entities/product.h"
#include "builder/productbuilder.h"

class ProductModel : public AbstractListModel
{
public:
    ProductModel(QObject *parent=nullptr);
    Product getById(int id) const;
    std::vector<Product> getDependanceOf(const Product& product);
    // QAbstractItemModel interface
public:
    QVariant data(const QModelIndex &index, int role) const override;
    bool setData(const QModelIndex& index, const QVariant& value, int role) override;

protected:
    virtual void initEntities() override;
    virtual void makeEntity(const QModelIndex &index, const QVariant &variant) override;

    void deleteProduct(Product&);
};

#endif // PRODUCT_MODEL_H
