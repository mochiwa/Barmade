#ifndef EMPLOYEE_ABSTRACTDAO_H
#define EMPLOYEE_ABSTRACTDAO_H


#include "abstractdao.h"
#include "entities/employee.h"

class EmployeeAbstractDao : public AbstractDao<Employee>
{
public:
    EmployeeAbstractDao(QSqlDatabase &db):AbstractDao(db){}
    virtual ~EmployeeAbstractDao();

    virtual Employee getEmployeeByCode(const QString& code)const=0 ;
    virtual std::unique_ptr<std::vector<std::unique_ptr<Employee>>> getAll()const=0;

};

#endif // EMPLOYEE_ABSTRACTDAO_H
