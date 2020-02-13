#include <QtTest>
#include <QCoreApplication>

#include "entities/product.h"
#include "business/productbusiness.h"

class ProductBusiness : public QObject
{
    Q_OBJECT

public:
    ProductBusiness();
    ~ProductBusiness();

private slots:
    void test_use_composed_product_with_suffisance_stock();

};

ProductBusiness::ProductBusiness()
{

}

ProductBusiness::~ProductBusiness()
{

}

void ProductBusiness::test_use_composed_product_with_suffisance_stock()
{
    //Has a Waiter

    //I want to

}


QTEST_MAIN(ProductBusiness)

#include "tst_productbusiness.moc"
