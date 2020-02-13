#include "typeemploye_dao.h"

TypeEmployeDao::TypeEmployeDao(QSqlDatabase &db):
    TypeEmployeeAbstractDao (db)
{
    init();
}

void TypeEmployeDao::create(TypeEmployee &t) const
{
    QSqlQuery q(db);
    q.prepare("SELECT f_create_type_employee(:name)");
    q.bindValue(":name",t.getName());
    q.exec();
    if(q.next())
        t.setId(q.value(0).toInt());
}

void TypeEmployeDao::update(const TypeEmployee &t) const
{
    Q_UNUSED(t);
    //nothing
}

void TypeEmployeDao::remove(const TypeEmployee &t) const
{
    Q_UNUSED(t);
    //nothing
}

TypeEmployee TypeEmployeDao::getById(int id) const
{
    TypeEmployee t;
    QSqlQuery q(db);
    q.prepare("SELECT * FROM f_get_types_employee() WHERE id_type_emp=:id");
    q.bindValue(":id",id);
    q.exec();
    if(q.next())
    {
        t.setId(q.value("id_type_emp").toInt());
        t.setName(q.value("name_type_emp").toString());
    }
    return t;
}


//protected
void TypeEmployeDao::init()
{
}
