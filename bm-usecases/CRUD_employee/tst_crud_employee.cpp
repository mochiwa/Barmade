#include <QtTest>
#include <QCoreApplication>
#include <QDebug>

#include "entities/employee.h"
#include "models/employee_model.h"

class crud_employee : public QObject
{
    Q_OBJECT

public:
    crud_employee();
    ~crud_employee();


    TypeEmployee manager;
    TypeEmployee waiter;

private slots:
    void create_an_employee();
    void create_two_employee();
    void read_an_employee();
    void update_an_employee();
    void delete_an_employee();
    void append_planning_to_an_employee();



};

crud_employee::crud_employee()
{
    manager.setName("manager");
    waiter.setName("waiter");

}

crud_employee::~crud_employee()
{

}

void crud_employee::create_an_employee()
{
    EmployeeModel EmployeeModel(this);
    //Given I'm auth like the manager
    Employee manager;
    manager.setType(this->manager);

    //And I want to add a new "<Employee>" in my program
    Employee employee;
    //When I append "<Employee>" with his "<personal informations>"
    EmployeeModel.append(employee);
    //Then the new "<Employee>" is append to the program
    QCOMPARE(EmployeeModel.rowCount(),1);

}

void crud_employee::create_two_employee()
{
    EmployeeModel EmployeeModel(this);
    //Given I'm auth like the manager
    Employee manager;
    manager.setType(this->manager);
    QCOMPARE(manager.getType(),this->manager);
    //And I want to add 2 new "<Employee>" in my program
    Employee employee1=Employee();
    Employee employee2=Employee();
    //When I append "<Employee>" with his "<personal informations>"
    EmployeeModel.append(employee1);
    EmployeeModel.append(employee2);
    //Then the new "<Employee>" is append to the program
    QCOMPARE(EmployeeModel.rowCount(),2);

}

void crud_employee::read_an_employee()
{
    EmployeeModel EmployeeModel(this);
//Given I'm the manager
    Employee manager;
    manager.setType(this->manager);
//And I have one "<employee"> in my program
    EmployeeModel.append(Employee());
//And i want to read "<personal informations>" from an "<employee>" in my program
    Employee emp;
//When i select the "<employee>"
    emp.fromVariant(EmployeeModel.data(EmployeeModel.index(0),EmployeeModel::Roles::VariantRole));
//Then i can read "<personal informations>" about the "<employee>"
    qDebug() << emp.toString();
    QVERIFY(!(emp.toString()==""));
}

void crud_employee::update_an_employee()
{
    QString name="john";
    QString nameModified="thierry";
    EmployeeModel EmployeeModel(this);


//Given I'm the manager
    Employee manager;
    manager.setType(this->manager);
//And i want to edit "<personal informations>" from an "<employee>" in my program
    EmployeeModel.append(Employee());
//When i select the "<employee>"
    Employee emp;
    emp.fromVariant(EmployeeModel.data(EmployeeModel.index(0),EmployeeModel::Roles::VariantRole));
//Then i can edit "<personal informations>" about the "<employee>"
    emp.setName(nameModified);
//And I can save "<personal informations>" edited into the program
    EmployeeModel.setData(EmployeeModel.index(0),emp.toVariant(),EmployeeModel::Roles::VariantRole);
    emp.setName(name);
    emp.fromVariant(EmployeeModel.data(EmployeeModel.index(0),EmployeeModel::Roles::VariantRole));
    QCOMPARE(emp.getName(),nameModified);
}

void crud_employee::delete_an_employee()
{

}

void crud_employee::append_planning_to_an_employee()
{
    EmployeeModel EmployeeModel(this);
    Employee emp;
    QList<const Planning *> plannings;
    plannings.append(new Planning(1,QDateTime(),QDateTime()));
    plannings.append(new Planning(2,QDateTime(),QDateTime()));

    EmployeeModel.append(Employee());
    emp.fromVariant(EmployeeModel.data(EmployeeModel.index(0),EmployeeModel::Roles::VariantRole));
    emp.setPlannings(plannings);

    QCOMPARE(emp.getPlannings().at(0)->getBegin(),QDateTime());
}

QTEST_MAIN(crud_employee)

#include "tst_crud_employee.moc"
