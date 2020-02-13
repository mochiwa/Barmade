#include <QtTest>
#include <QCoreApplication>

#include "entities/employee.h"
#include "business/authenticator.h"


class authentication_employee : public QObject
{
    Q_OBJECT

public:
    authentication_employee();
    ~authentication_employee();

private slots:
    void try_to_loging_with_correct_id();
};

authentication_employee::authentication_employee()
{

}

authentication_employee::~authentication_employee()
{

}

void authentication_employee::try_to_loging_with_correct_id()
{
    QString code="0001";

//Given I'm a "<employee>" not logged
    Employee employee;
//And I want to access to the application
    Authenticator auth;
//When I put my "<employee_code>"
    auth.login(code);
//Then the application load my profile
    QCOMPARE(employee.getCode(),code);
//give me an access to the application if i have the "<right>"
    //not implemted
}

QTEST_MAIN(authentication_employee)

#include "tst_authentication_employee.moc"
