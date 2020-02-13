#include "invoice_dao.h"

using namespace std;
InvoiceDao::InvoiceDao(QSqlDatabase &db):
    InvoiceAbstractDao (db)
{
    init();
}
void InvoiceDao::create(Invoice &o) const
{
    QSqlQuery q(db);
    q.prepare("SELECT f_create_order(:stakeholder,:time,:price)");
    q.bindValue(":stakeholder",o.getIdStakeholder());
    q.bindValue(":time",o.getTransactionTime());
    q.bindValue(":price",o.getPrice());
    q.exec();
    if(q.next())
        o.setId(q.value(0).toInt());
}

void InvoiceDao::update(const Invoice &o) const
{
    QSqlQuery q(db);
    q.prepare("SELECT f_update_order(:id,:stakeholder,:time,:price,:delete)");
    q.bindValue(":id",o.getId());
    q.bindValue(":stakeholder",o.getIdStakeholder());
    q.bindValue(":time",o.getTransactionTime());
    q.bindValue(":price",o.getPrice());
    q.bindValue(":delete",o.isDeleted());
    q.exec();
}

void InvoiceDao::remove(const Invoice &o) const
{
    Q_UNUSED(o);
}

Invoice InvoiceDao::getById(int id) const
{
    Invoice o;
    QSqlQuery q(db);
    q.prepare("SELECT * FROM f_get_orders() WHERE id_order=:id");
    q.bindValue("id",id);
    q.exec();
    if(q.next())
    {
        o.setId(q.value("id_order").toInt());
        o.setIdStakeholder(q.value("id_stakeholder").toInt());
        o.setTransactionTime(q.value("transaction_order").toDateTime());
        o.setPrice(q.value("price_order").toFloat());
        o.setDeleted(q.value("deleted_order").toBool());
    }
    return o;
}

std::unique_ptr<std::vector<std::unique_ptr<Invoice> > > InvoiceDao::getAll() const
{
    QSqlQuery q(db);
    unique_ptr<vector<unique_ptr<Invoice>>> list(new vector<unique_ptr<Invoice>>);

    q.prepare("SELECT * FROM f_get_orders()");
    q.exec();
    if(q.next())
    {
        unique_ptr<Invoice> o(new Invoice());
        o->setId(q.value("id_order").toInt());
        o->setIdStakeholder(q.value("id_stakeholder").toInt());
        o->setTransactionTime(q.value("time_transaction").toDateTime());
        o->setPrice(q.value("price_order").toFloat());
        o->setDeleted(q.value("deleted_order").toBool());
        list->push_back(move(o));
    }
    return list;
}

std::unique_ptr<std::vector<std::unique_ptr<Invoice> > > InvoiceDao::getOrdersByStakeholder(int stakeholder) const
{
    QSqlQuery q(db);
    unique_ptr<vector<unique_ptr<Invoice>>> list(new vector<unique_ptr<Invoice>>);

    q.prepare("SELECT * FROM f_get_orders() WHERE id_stakeholder=:id");
    q.bindValue(":id",stakeholder);
    q.exec();
    while(q.next())
    {
        unique_ptr<Invoice> o(new Invoice());
        o->setId(q.value("id_order").toInt());
        o->setIdStakeholder(q.value("id_stakeholder").toInt());
        o->setTransactionTime(q.value("time_transaction").toDateTime());
        o->setPrice(q.value("price_order").toFloat());
        o->setDeleted(q.value("deleted_order").toBool());
        list->push_back(move(o));
    }
    return list;
}

void InvoiceDao::init()
{

}
