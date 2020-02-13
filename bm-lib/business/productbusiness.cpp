#include "productbusiness.h"
using namespace std;
ProductBusiness::ProductBusiness(QObject *parent):
    QObject (parent)
{}

ProductBusiness::ProductBusiness(AbstractListModel *model, QObject *parent):
    QObject (parent)
{
    this->model=model;
}


//------------- SLOTS -------------//

//------------- PRIVATE -------------//
void ProductBusiness::updateDependance(const Product& product)
{
    ProductModel *productModel=static_cast<ProductModel*>(model);
    for(auto p:productModel->getDependanceOf(product))
        stockManagement(p);
}
void ProductBusiness::increaseUsed(Product &product, const Capacity &quantity)
{
    Capacity toAppend=product.getUsed()+quantity;
    if(toAppend>=product.getCapacity())
        decreaseStock(product,toAppend);
    else
        product.setUsed(toAppend);
    updateProductModel(product);
}
void ProductBusiness::decreaseStock(Product &product, const Capacity &quantity)
{
    Capacity toAppend=quantity-product.getCapacity();
    product.setStock(product.getStock()-1);
    increaseUsed(product,toAppend);
}
void ProductBusiness::updateProductModel(const Product &product)
{
    QModelIndex index=model->getIndexById(product.getId());
    model->setData(index,product.toVariant(),AbstractListModel::VariantRole);
}

//------------- PUBLIC -------------//

void ProductBusiness::stockManagement(Product& product)
{
    product.setStock(getStockUnity(product));
    if(product.getStock()<=product.getAlarm())
        emit stock_alarm(product);
    updateProductModel(product);
    updateDependance(product);
}
bool ProductBusiness::checkStockEnough(const QMap<int, int> &map)
{
    ProductModel *productModel=static_cast<ProductModel*>(model);
    QMap<int, int>::ConstIterator it;
    QMap<Product,Capacity> stocks;
    QMap<Product,Capacity>::iterator itStock;
    Product p;

    for(it=map.begin();it!=map.end();it++)
    {
        p=productModel->getById(it.key());
        if(p.getIngredients().size())
            appendStockIngredient(stocks,p,it.value());
        else
            stocks.insert(p,p.getCapacity()*it.value());
    }

    for(itStock=stocks.begin();itStock!=stocks.end();itStock++)
        if(getStockCapacity(itStock.key())<itStock.value())
        {
            emit stock_not_enough(itStock.key());
            return false;
        }
    return true;
}

void ProductBusiness::appendStockIngredient(QMap<Product, Capacity> &stocks,const Product& p,int qty)
{
    Product product;
    ProductModel *productModel=static_cast<ProductModel*>(model);
    Capacity capacity;
    for(auto i:p.getIngredients())
    {
        product=productModel->getById(i.getIngredient());

        if(!stocks.contains(product))
            stocks.insert(product,i.getQuantity()*qty);
        else
        {
            capacity=stocks.value(product)+i.getQuantity()*qty;
            stocks.remove(product);
            stocks.insert(product,capacity);
        }
    }
}

void ProductBusiness::setProductCapacity(Product &product)
{
    Capacity c;
    if(product.getIngredients().size()>0)
    {
        for(auto const& i:product.getIngredients())
            c=c+i.getQuantity();
        product.setCapacity(c);
    }
    updateProductModel(product);
}

void ProductBusiness::processDebit(Product &product)
{
    Product ingredient;
    for(auto const& i:product.getIngredients())
    {
        ingredient=getProduct(i.getIngredient());
        increaseUsed(ingredient,i.getQuantity());
    }
    increaseUsed(product,product.getCapacity());
    stockManagement(product);
}

void ProductBusiness::processCredit(Product &product,int quantity)
{
    product.setStock(product.getStock()+quantity);
    stockManagement(product);
}

Capacity ProductBusiness::getStockCapacity(const Product &product) const
{
    if(product.getIngredients().size()>0)
        return getStockCapacity(getProductByTinyStock(product.getIngredients()));

    Capacity stock;
    float productCapacity=product.getCapacity()*product.getStock();
    float productUsed=product.getUsed();

    stock.setValue(productCapacity-productUsed);
    return stock;
}


int ProductBusiness::getStockUnity(const Product &product) const
{
    if(product.getIngredients().size()==0)
        return product.getStock();

    Product p=getProductByTinyStockUsed(product.getIngredients());

    for(auto i:product.getIngredients())
        if(i.getIngredient()==p.getId())
            return static_cast<int>(getStockCapacity(p)/i.getQuantity());

    return -1;
}
Product ProductBusiness::getProductByTinyStock(const std::vector<Ingredient>& in) const
{
    stockSearch search;
    StockComparison comparison;
    vector<Product> ingredients;
    for(auto i : in)
        ingredients.push_back(getProduct(i.getIngredient()));
    return search.search(ingredients,comparison);
}

Product ProductBusiness::getProductByTinyStockUsed(const std::vector<Ingredient>& in) const
{
    IngredientSearch search;
    IngredientUsedComparison comparison(this);
    Ingredient tiny=search.search(in,comparison);
    return getProduct(tiny.getIngredient());
}

//-------- Getter & Setter ---------//

void ProductBusiness::setModel(AbstractListModel *value)
{
    model = value;
}

Product ProductBusiness::getProduct(int id) const
{
    QModelIndex index;
    Product product;
    index=model->getIndexById(id);
    product.fromVariant(model->data(index,AbstractListModel::VariantRole));
    return product;
}


