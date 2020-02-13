#include <QtTest>
#include <QCoreApplication>

#include "sql/dao/postgres/city_dao.h"
#include "sql/dao/postgres/street_dao.h"
#include "sql/dao/postgres/typeemploye_dao.h"
#include "sql/dao/postgres/employee_dao.h"
#include "sql/database_manager.h"

using namespace std;
class daoPostgres : public QObject
{
    Q_OBJECT

public:
    daoPostgres();
    ~daoPostgres();

private slots:
    void test_db_connection();
    //city
    void test_create_a_new_city();
    void test_get_a_city_by_id();
    void test_update_a_existant_city();
    //street
    void test_create_a_new_street();
    void test_get_a_street_by_id();
    void test_update_a_existant_street();
    //entity
    void test_create_a_new_entity();
    void test_get_a_entity_by_id();
    void test_update_a_existant_entity();
    //type employee
    void test_create_a_new_typeEmployee();
    void test_get_a_typeEmployee_by_id();
    void test_update_a_existant_typeEmployee();
    //employee
    void test_create_a_new_employee();
    void test_get_a_employee_by_id();
    void test_update_a_existant_employee();
    void test_get_all_employees();

private:
    DatabaseManager *manager;
    City city;
    Street street;
    TypeEmployee typeEmployee;
    Entity entity;
    Employee employee;
};

daoPostgres::daoPostgres()
{
    manager=&DatabaseManager::getInstance();
    city=manager->cityDao->getById(2);
    street=manager->streetDao->getById(2);
    typeEmployee=manager->typeEmployeeDao->getById(2);
    entity=manager->entityDao->getById(2);
    employee=manager->employeeDao->getById(2);
}

daoPostgres::~daoPostgres()
{

}

void daoPostgres::test_db_connection()
{
    QCOMPARE(manager->getdb().isOpen(),true);
}

void daoPostgres::test_create_a_new_city()
{
    City c;
    c.setName("test_generate");
    c.setCp("test_generate");
    this->manager->cityDao->create(c);
    QVERIFY(c.getId()!=-1);
}
void daoPostgres::test_get_a_city_by_id()
{
    City c;
    c=this->manager->cityDao->getById(2);
    QVERIFY(c.getId()!=-1);
}
void daoPostgres::test_update_a_existant_city()
{
    City c;
    City copy;
    c=manager->cityDao->getById(2);
    if(!c.getName().compare("teste"))
        c.setName("teste2");
    else
        c.setName("teste");
    manager->cityDao->update(c);
    copy=manager->cityDao->getById(2);
    QVERIFY(c==copy);
}

//  street
void daoPostgres::test_create_a_new_street()
{
    Street s;
    s.setName("test_generate");
    s.setNumber("test_generate");
    s.setId_city(2);
    this->manager->streetDao->create(s);

    QVERIFY(s.getId()!=-1);
}
void daoPostgres::test_get_a_street_by_id()
{
    Street s;
    s=this->manager->streetDao->getById(2);
    QVERIFY(s.getId()!=-1);
}
void daoPostgres::test_update_a_existant_street()
{
    Street s;
    Street copy;
    s=manager->streetDao->getById(2);
    copy=s;
    if(!s.getName().compare("test1"))
        s.setName("test2");
    else
        s.setName("test1");
    manager->streetDao->update(s);
    copy=manager->streetDao->getById(2);
    QVERIFY(s==copy);
}

//entity
void daoPostgres::test_create_a_new_entity()
{
    Entity e;
    e.setName("test_generate");
    e.setForename("test_generate");
    e.setPhone("test_generate");
    e.setBirthday(QDate::currentDate());
    e.setCode("#0001test_generate");
    e.setPicture("test_generate/picture/test_generate");
    e.setStreet(street);
    e.setCity(city);
    manager->entityDao->create(e);
    QVERIFY(e.getId()!=-1);
}
void daoPostgres::test_get_a_entity_by_id()
{
    Entity e;
    e=manager->entityDao->getById(2);
    QVERIFY(e.getId()==2);
}
void daoPostgres::test_update_a_existant_entity()
{
    Entity e;
    Entity copy;
    e=this->manager->entityDao->getById(2);
    copy=e;
    if(!e.getName().compare("test"))
        e.setName("test2");
    else
        e.setName("test");
    this->manager->entityDao->update(e);
    copy=this->manager->entityDao->getById(2);
    QVERIFY(e==copy);
}

//typeemployee
void daoPostgres::test_create_a_new_typeEmployee()
{
    TypeEmployee t;
    t.setName("manager");
    this->manager->typeEmployeeDao->create(t);
    QVERIFY(t.getId()!=-1);
}
void daoPostgres::test_get_a_typeEmployee_by_id()
{
    TypeEmployee t;
    t=this->manager->typeEmployeeDao->getById(1);
    QVERIFY(t.getId()!=-1);
}
void daoPostgres::test_update_a_existant_typeEmployee()
{

}

//employee
void daoPostgres::test_create_a_new_employee()
{
    Employee e;

    e=entity;
    e.setCity(city);
    e.setStreet(street);
    e.setSalary(2000);
    e.setType(typeEmployee);
    this->manager->employeeDao->create(e);
    QVERIFY(e.getId()!=-1);
}
void daoPostgres::test_get_a_employee_by_id()
{
    Employee e;
    e=this->manager->employeeDao->getById(2);
    QVERIFY(e.getId()!=-1);
}
void daoPostgres::test_update_a_existant_employee()
{
    Employee e=this->manager->employeeDao->getById(2);
    Employee copy;
    if(!e.getName().compare("nicolas"))
        e.setName("pierre");
    else
        e.setName("nicolas");
    this->manager->employeeDao->update(e);
    copy=this->manager->employeeDao->getById(2);
    QVERIFY(e.getId()==copy.getId());
}

void daoPostgres::test_get_all_employees()
{
    unique_ptr<vector<unique_ptr<Employee>>> list=manager->employeeDao->getAll();
    QVERIFY(list->size()>0);
}

QTEST_MAIN(daoPostgres)

#include "tst_daopostgres.moc"
