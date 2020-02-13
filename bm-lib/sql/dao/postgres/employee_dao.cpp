#include "employee_dao.h"


using namespace std;

EmployeeDao::EmployeeDao(QSqlDatabase &db):
    EmployeeAbstractDao (db)
{
    init();
}

EmployeeDao::~EmployeeDao()
{
}

void EmployeeDao::create(Employee &e)const
{
    QSqlQuery q(db);
    q.prepare("SELECT f_create_employee(:id,:salary,:type)");
    q.bindValue(":id",e.getId());
    q.bindValue(":salary",e.getSalary());
    q.bindValue(":type",e.getType().getId());
    q.exec();
    if(q.next())
        e.setId(q.value(0).toInt());
}
void EmployeeDao::update(const Employee &e)const
{
    QSqlQuery q(db);
    q.setForwardOnly(true);
    q.prepare("SELECT f_update_employee(:id,:salary,:type)");
    q.bindValue(":id",e.getId());
    q.bindValue(":type",e.getType().getId());
    q.bindValue(":salary",e.getSalary());
    q.exec();
}
void EmployeeDao::remove(const Employee &e)const
{
    Q_UNUSED(e);
}
Employee EmployeeDao::getById(int id)const
{
    Employee e;
    QSqlQuery q(db);

    q.prepare("SELECT * from f_get_employees() WHERE id_employee=:id");
    q.bindValue(":id",id);
    q.exec();
    if(q.next())
    {
        e.setId(q.value("id_employee").toInt());
        e.setSalary(q.value("salary_employee").toFloat());
        e.setType(TypeEmployee(q.value("id_type_emp").toInt()));
    }
    return e;
}

unique_ptr<vector<unique_ptr<Employee>>> EmployeeDao::getAll()const
{
    QSqlQuery q(db);
    unique_ptr<vector<unique_ptr<Employee>>> list(new vector<unique_ptr<Employee>>);
    q.exec("SELECT * FROM f_get_employees_where_deleted(false)");
    while(q.next())
    {
        unique_ptr<Employee> e(new Employee());
        e->setId(q.value("id_employee").toInt());
        e->setSalary(q.value("salary_employee").toFloat());
        e->setType(TypeEmployee(q.value("id_type_emp").toInt()));
        list->push_back(move(e));
    }
    return list;
}

Employee EmployeeDao::getEmployeeByCode(const QString &code) const
{
    QSqlQuery q(db);
    Employee e;
    q.prepare("SELECT * FROM f_get_employee_by_code(:code)");
    q.bindValue(":code",code);
    q.exec();
    if(q.next())
    {
        e.setId(q.value("id_employee").toInt());
        e.setSalary(q.value("salary_employee").toFloat());
        e.setType(TypeEmployee(q.value("id_type_emp").toInt()));
    }
    return e;
}

void EmployeeDao::init()
{

}
