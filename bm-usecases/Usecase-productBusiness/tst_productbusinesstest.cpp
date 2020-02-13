#include <QtTest>
#include <QCoreApplication>

// add necessary includes here

class ProductBusinessTest : public QObject
{
    Q_OBJECT

public:
    ProductBusiness();
    ~ProductBusiness();

private slots:
    void test_case1();

};

ProductBusiness::ProductBusiness()
{

}

ProductBusiness::~ProductBusiness()
{

}

void ProductBusiness::test_case1()
{

}

QTEST_MAIN(ProductBusinessTest)

#include "tst_productbusinesstest.moc"
