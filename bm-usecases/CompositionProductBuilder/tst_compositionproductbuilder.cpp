#include <QtTest>
#include <QCoreApplication>
#include "sql/database_manager.h"

using namespace std;
class CompositionProductBuilder : public QObject
{
    Q_OBJECT

public:
    CompositionProductBuilder();
    ~CompositionProductBuilder();

private slots:
    void test_build_product();
    void test_load_product();
    void test_build_composed_product();
    void test_update_composed_product();

};

CompositionProductBuilder::CompositionProductBuilder()
{

}

CompositionProductBuilder::~CompositionProductBuilder()
{

}


void CompositionProductBuilder::test_build_product()
{
    Product p;
    p.setName("coca");
    p.setPicture(" ");
    p.setPrice(2);
    p.setStock(55);
    p.setAlarm(12);
    p.setRemainder(33);
    p.setCapacity(33);
    ProductBuilder::getInstance().build(p);

}

void CompositionProductBuilder::test_load_product()
{
    Product p=DatabaseManager::getInstance().productDao->getById(3);
    Product s;
    s.setId(p.getId());
    ProductBuilder::getInstance().load(s);
    QVERIFY(s==p);
}

void CompositionProductBuilder::test_build_composed_product()
{
    Product p;
    p.setName("coca");
    p.setPicture(" ");
    p.setPrice(2);
    p.setStock(55);
    p.setAlarm(12);
    p.setRemainder(33);
    p.setCapacity(33);
    ProductBuilder::getInstance().build(p);

    Product a;
    a.setName("rhum");
    a.setPicture(" ");
    a.setPrice(7);
    a.setStock(3);
    a.setAlarm(12);
    a.setRemainder(33);
    a.setCapacity(33);
    ProductBuilder::getInstance().build(a);

    Product final;
    final.setName("rhum coca");
    final.setPicture("");
    final.setPrice(p.getPrice().getValue()+a.getPrice().getValue());
    final.setStock(3);//functionCalcul stock
    final.setAlarm(12);
    final.setRemainder(33);//calcul rest
    final.setCapacity(33);
    ProductComposition c1(p.getId(),final.getId(),33);
    ProductComposition c2(a.getId(),final.getId(),5);
    ProductBuilder::getInstance().build(final);
    DatabaseManager::getInstance().productCompositionDao->create(c1);
    DatabaseManager::getInstance().productCompositionDao->create(c2);
    ProductBuilder::getInstance().load(final);
    QVERIFY(final.getCompositions().size()>0);
}

void CompositionProductBuilder::test_update_composed_product()
{
    Product p=DatabaseManager::getInstance().productDao->getById(10);
    Product cpy;

    ProductBuilder::getInstance().load(p);
    vector<ProductComposition> c=p.getCompositions();

    c.at(0).setIsDelete(true);
    p.setCompositions(c);

    ProductBuilder::getInstance().update(p);

    cpy.setId(p.getId());
    ProductBuilder::getInstance().load(cpy);
    QVERIFY(cpy==p);

    if(cpy==p)
    {
        c.at(0).setIsDelete(false);
        p.setCompositions(c);
        ProductBuilder::getInstance().update(p);
        ProductBuilder::getInstance().load(p);
    }
}
QTEST_MAIN(CompositionProductBuilder)

#include "tst_compositionproductbuilder.moc"
