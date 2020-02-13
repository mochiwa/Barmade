#include "compositionorder_dao.h"

CompositionOrderDao::CompositionOrderDao(QSqlDatabase &db):
    CompositionOrderAbstractDao(db)
{

}

void CompositionOrderDao::create(CompositionOrder & c) const
{
    QSqlQuery q(db);
    q.prepare("SELECT f_append_to_order(:order,:product,:qty)");
    q.bindValue(":order",c.getIdOrder());
    q.bindValue(":product",c.getIdProduct());
    q.bindValue(":qty",c.getQuantity());
    q.exec();
}

void CompositionOrderDao::update(const CompositionOrder &c) const
{
    QSqlQuery q(db);
    q.prepare("SELECT f_update_orderComposition(:order,:product,:qty)");
    q.bindValue(":order",c.getIdOrder());
    q.bindValue(":product",c.getIdProduct());
    q.bindValue(":qty",c.getQuantity());
    q.exec();
}

void CompositionOrderDao::remove(const CompositionOrder &c) const
{
    QSqlQuery q(db);
    q.prepare("SELECT f_delete_orderComposition(:order,:product)");
    q.bindValue(":order",c.getIdOrder());
    q.bindValue(":product",c.getIdProduct());
    q.exec();
}

CompositionOrder CompositionOrderDao::getById(int id) const
{
    Q_UNUSED(id);
    return CompositionOrder();
}

std::vector<CompositionOrder> CompositionOrderDao::getByOrder(int idOrder) const
{
    std::vector<CompositionOrder> compositions;

    QSqlQuery q(db);
    q.prepare("SELECT * FROM f_get_orderComposition_by_order(:id)");
    q.bindValue(":id",idOrder);
    q.exec();
    while(q.next())
    {
        CompositionOrder c;
        c.setIdOrder(q.value("id_order").toInt());
        c.setIdProduct(q.value("id_product").toInt());
        c.setQuantity(q.value("quantity_ordered").toInt());
        compositions.push_back(c);
    }
    return compositions;
}

void CompositionOrderDao::init()
{
}
