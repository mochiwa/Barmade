#include <QtTest>
#include <QCoreApplication>

#include "sql/database_manager.h"

class DaoProduct : public QObject
{
    Q_OBJECT

public:
    DaoProduct();
    ~DaoProduct();

private slots:
    void test_create_product();
    void test_get_product_by_id();
    void test_update_product();
    void test_get_products();
};

DaoProduct::DaoProduct()
{

}

DaoProduct::~DaoProduct()
{

}

void DaoProduct::test_create_product()
{
    Product p;
    p.setName("fanta");
    p.setPicture(" ");
    p.setPrice(2);
    p.setStock(55);
    p.setAlarm(12);
    p.setRemainder(33);
    p.setCapacity(33);
    DatabaseManager::getInstance().productDao->create(p);
    QVERIFY(p.getId()!=-1);
}

void DaoProduct::test_get_product_by_id()
{
    Product p =DatabaseManager::getInstance().productDao->getById(1);
    QVERIFY(p.getId()!=-1);
}

void DaoProduct::test_update_product()
{
    Product p=DatabaseManager::getInstance().productDao->getById(1);
    Product copy;
    if(p.getPrice()==2.f)
        p.setPrice(3);
    else
        p.setPrice(2);
    DatabaseManager::getInstance().productDao->update(p);
    copy=DatabaseManager::getInstance().productDao->getById(1);
    QVERIFY(p==copy);
}

void DaoProduct::test_get_products()
{
    QVERIFY(DatabaseManager::getInstance().productDao->getAll()->size()>0);
}



QTEST_MAIN(DaoProduct)

#include "tst_daoproduct.moc"
