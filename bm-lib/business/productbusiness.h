#ifndef PRODUCTBUSINESS_H
#define PRODUCTBUSINESS_H

#include <QObject>
#include <vector>
#include <QMap>
#include "models/invoice_model.h"
#include "models/product_model.h"
#include "sql/database_manager.h"

#include "specifications/stock/stocksearch.h"
#include "specifications/stock/stockcomparison.h"

#include "specifications/ingredient/ingredientsearch.h"
#include "specifications/ingredient/ingredientusedcomparison.h"

class ProductBusiness : public QObject
{
    Q_OBJECT
public:
    ProductBusiness(QObject *parent=nullptr);
    ProductBusiness(AbstractListModel *model,QObject *parent=nullptr);
    void setProductCapacity(Product& product);
    /**
     * @brief set 'stock unity' of a product
     * set the stock by unity to a product, if the stock
     * is less than the 'product alert' then signal(stock_alarm) is emit.
     */
    void stockManagement(Product& product);

    bool checkStockEnough(const QMap<int,int>&map);
    void appendStockIngredient(QMap<Product,Capacity>& stocks,const Product& p,int qty);

    void processDebit(Product& product);
    void processCredit(Product& product, int quantity);

    /**
     * @brief getStockCapacity
     * @param product
     * @return return the stock in Capacity
     */
    Capacity getStockCapacity(const Product& product)const;
    /**
     * @brief getStockUnity
     * @param product
     * @return the stock by unity
     */
    int getStockUnity(const Product& product) const;

    /**
     * @brief getProductByTinyStock
     * @param ingredients
     * @return search among ingredients which is has the tiny stock
     */
    Product getProductByTinyStock(const std::vector<Ingredient>& ingredients) const;
    /**
     * @brief getProductByTinyStockUsed
     * @param ingredients
     * @return search among ingredients which is has the tiny stock
     *  when the capacity sell is calculate
     */
    Product getProductByTinyStockUsed(const std::vector<Ingredient>& ingredients) const;

    void setModel(AbstractListModel *value);
    Product getProduct(int id) const;

private:
    void updateDependance(const Product &product);
    void increaseUsed(Product& product,const Capacity& quantity);
    void decreaseStock(Product& product,const Capacity& quantity);
    void updateProductModel(const Product& product);

signals:
    void stock_alarm(const Product&);
    void stock_not_enough(const Product& p);

private:
    AbstractListModel *model;
};

#endif // PRODUCTBUSINESS_H
