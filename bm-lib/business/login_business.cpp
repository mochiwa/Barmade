#include "login_business.h"

LoginBusiness::LoginBusiness(QObject *parent):
    QObject(parent)
{

}

LoginBusiness::~LoginBusiness()
{
}

void LoginBusiness::process(const QString &input)
{
    Employee employee;
    employee=DatabaseManager::getInstance().employeeDao->getEmployeeByCode(input);
    if(employee.getId()==-1)
        emit login_notFound();
    else
    {
        EmployeeBuilder::getInstance().load(employee);
        emit login_found(employee);
    }
}
