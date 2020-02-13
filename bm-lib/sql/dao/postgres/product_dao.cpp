#include "product_dao.h"
using namespace std;

ProductDao::ProductDao(QSqlDatabase &db):ProductAbstractDo (db)
{
    init();
}

void ProductDao::create(Product &p) const
{
    QSqlQuery q(db);
    q.prepare("SELECT f_create_product(:name,:picture,:price,:stock,:capacity,:remainder,:alarm)");
    q.bindValue(":name",p.getName());
    q.bindValue(":picture",p.getPicture());
    q.bindValue(":price",p.getPrice().getValue());
    q.bindValue(":stock",p.getStock());
    q.bindValue(":capacity",p.getCapacity().getValue());
    q.bindValue(":remainder",p.getUsed().getValue());
    q.bindValue(":alarm",p.getAlarm());
    q.exec();
    if(q.next())
        p.setId(q.value(0).toInt());
}

void ProductDao::update(const Product &p) const
{
    QSqlQuery q(db);
    q.prepare("select f_update_product(:id,:isDelete,:name,:picture,:price,:stock,:capacity,:remainder,:alarm)");
    q.bindValue(":id",p.getId());
    q.bindValue(":isDelete",p.getIsDelete());
    q.bindValue(":name",p.getName());
    q.bindValue(":picture",p.getPicture());
    q.bindValue(":price",p.getPrice().getValue());
    q.bindValue(":stock",p.getStock());
    q.bindValue(":capacity",p.getCapacity().getValue());
    q.bindValue(":remainder",p.getUsed().getValue());
    q.bindValue(":alarm",p.getAlarm());
    q.exec();
}

void ProductDao::remove(const Product &p) const
{
    Q_UNUSED(p);
}

Product ProductDao::getById(int id) const
{
    Product p;
    QSqlQuery q(db);
    q.prepare("SElECT * FROM f_get_products() WHERE id_product=:id");
    q.bindValue(":id",id);
    q.exec();
    if(q.next())
    {
        p.setId(q.value("id_product").toInt());
        p.setIsDelete(q.value("isDelete_product").toBool());
        p.setName(q.value("name_product").toString());
        p.setPicture(q.value("picture_product").toString());
        p.setPrice(q.value("price_product").toFloat());
        p.setStock(q.value("quantity_stock").toInt());
        p.setCapacity(q.value("centiliter_capacity").toFloat());
        p.setUsed(q.value("centiliter_remainder").toFloat());
        p.setAlarm(q.value("alarm_count").toInt());
    }
    return p;
}
unique_ptr<vector<unique_ptr<Product>>> ProductDao::getAll() const
{
    unique_ptr<vector<unique_ptr<Product>>>list(new vector<unique_ptr<Product>>);
    QSqlQuery q(db);
    q.exec("SElECT * FROM f_get_products() WHERE isDelete_product=false");
    while(q.next())
    {
        unique_ptr<Product> p(new Product());
        p->setId(q.value("id_product").toInt());
        p->setIsDelete(q.value("isDelete_product").toBool());
        p->setName(q.value("name_product").toString());
        p->setPicture(q.value("picture_product").toString());
        p->setPrice(q.value("price_product").toFloat());
        p->setStock(q.value("quantity_stock").toInt());
        p->setCapacity(q.value("centiliter_capacity").toFloat());
        p->setUsed(q.value("centiliter_remainder").toFloat());
        p->setAlarm(q.value("alarm_count").toInt());
        list->push_back(move(p));
    }
    return list;
}

void ProductDao::init()
{

}
