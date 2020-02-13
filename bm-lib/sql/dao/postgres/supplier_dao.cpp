#include "supplier_dao.h"
using namespace std;

SupplierDao::SupplierDao(QSqlDatabase &db):
    SupplierAbstractDao (db)
{
    init();
}

void SupplierDao::create(Supplier &s) const
{
    QSqlQuery q(db);
    q.prepare("SELECT f_create_supplier(:id,:fax)");
    q.bindValue(":id",s.getId());
    q.bindValue(":fax",s.getFax());
    q.exec();
    if(q.next())
        s.setId(q.value(0).toInt());
}

void SupplierDao::update(const Supplier &s) const
{
    QSqlQuery q(db);
    q.prepare("SELECT f_update_supplier(:id,:fax)");
    q.bindValue(":id",s.getId());
    q.bindValue(":fax",s.getFax());
    q.exec();
}


void SupplierDao::remove(const Supplier &s) const
{
    Q_UNUSED(s);
}

Supplier SupplierDao::getById(int id) const
{
    Supplier s;
    QSqlQuery q(db);

    q.prepare("SELECT * from f_get_suppliers() WHERE id_supplier=:id");
    q.bindValue(":id",id);
    q.exec();
    if(q.next())
    {
        s.setId(q.value("id_supplier").toInt());
        s.setFax(q.value("fax_supplier").toString());
    }
    return s;
}

std::unique_ptr<std::vector<std::unique_ptr<Supplier>>> SupplierDao::getAll() const
{
    QSqlQuery q(db);
    unique_ptr<vector<unique_ptr<Supplier>>> list(new vector<unique_ptr<Supplier>>);
    q.exec("SELECT * FROM  f_get_suppliers_where_delete(false)");
    while(q.next())
    {
        unique_ptr<Supplier> e(new Supplier());
        e->setId(q.value("id_supplier").toInt());
        e->setFax(q.value("fax_supplier").toString());
        list->push_back(move(e));
    }
    return list;
}

void SupplierDao::init()
{

}
