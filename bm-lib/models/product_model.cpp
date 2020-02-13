#include "product_model.h"
using namespace std;
ProductModel::ProductModel(QObject * parent):
    AbstractListModel (parent)
{
    initEntities();
}

Product ProductModel::getById(int id) const
{
    Product product;
    for(auto const& p:*entities)
    {
        product.fromVariant(*p);
        if(product.getId()==id)
            return product;
    }
    return Product();
}

vector<Product> ProductModel::getDependanceOf(const Product &product)
{
    vector<Product> products;
    for(auto const& v:*entities)
    {
        Product p(*v);
        for(auto const& i:p.getIngredients())
            if(i.getIngredient()==product.getId())
            {
                products.push_back(p);
                break;
            }
    }
    return products;
}

void ProductModel::initEntities()
{
    unique_ptr<vector<unique_ptr<Product>>> products=ProductBuilder::getInstance().getAll();
    for(auto const& p:*products)
        append(p->toVariant());
}

void ProductModel::makeEntity(const QModelIndex &index, const QVariant &variant)
{
    Product p;
    p.fromVariant(variant);
    ProductBuilder::getInstance().build(p);
    setData(index,p.toVariant(),Roles::VariantRole);
}

void ProductModel::deleteProduct(Product& p)
{
    p.setIsDelete(true);
  /*  if(!db.productCompositionDao->getProductByIngredient(p.getId())->empty())
        append(p.toVariant());
    else
    {
        p.setIsDelete(true);
        auto list=db.productCompositionDao->getcomposition(p.getId());
        for(auto & it:*list)
            db.productCompositionDao->remove(*it);
    }*/
}


QVariant ProductModel::data(const QModelIndex &index, int role) const
{
    if(!isIndexValid(index))
        return QVariant();

    Product p;
    p.fromVariant(getEntity(index));
    switch (role)
    {
        case Qt::DisplayRole:
            return p.getName();
        case Roles::IdRole:
            return p.getId();
        case Roles::VariantRole:
            return p.toVariant();
        default:
            return QVariant();
    }
}

bool ProductModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
    if(!isIndexValid(index))
        return false;

    Product p;
    p.fromVariant(getEntity(index));
    switch (role) {
        case Roles::VariantRole:
            p.fromVariant(value);
            break;
        case Roles::DeleteRole:
            deleteProduct(p);
            break;
        case Roles::MakeEntity:
            makeEntity(index,value);
            p.fromVariant(data(index,Roles::VariantRole));
            break;
    }
    entities->at(static_cast<unsigned int>(index.row()))->setValue(p.toVariant());
    ProductBuilder::getInstance().update(p);
    emit dataChanged(index, index);
    return true;
}


