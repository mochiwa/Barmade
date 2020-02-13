#ifndef PRODUCTSTOCKORDER_H
#define PRODUCTSTOCKORDER_H

#include "components/abstracttablewidget.h"
#include "components/tablewidgetspinbox_delegate.h"
#include "entities/product.h"
#include "entities/invoice.h"
#include "models/product_model.h"
#include <vector>

class ProductStockOrder :public AbstractTableWidget
{
    Q_OBJECT
public:
    enum Column{Name,Stock,ToOrder,Price,Total};
    const int columnCount=5;

    ProductStockOrder(QWidget *parent =nullptr);
    ~ProductStockOrder();
    virtual QVariant build();
    void fillTable();
    void setProductModel(ProductModel *value);
    float sumTotalPrice();
    void resetTable();
public slots:
    virtual void updateLine(int row);

protected:
    virtual void initColumns();
    virtual void createRow(int row);
    virtual void incrementQuantity(int row);

private:
    float getTotalPriceForRow(int row);
    float getTotalPriceNoTVA();
private:
    ProductModel *productModel;

};
#endif // PRODUCTSTOCKORDER_H
