#ifndef EMPLOYEE_DAOPOSTGRES_H
#define EMPLOYEE_DAOPOSTGRES_H

#include "../employee_abstractdao.h"
class EmployeeDao : public EmployeeAbstractDao
{
public:
    EmployeeDao(QSqlDatabase &db);
    virtual ~EmployeeDao();

    // AbstractDao interface
public:
    virtual void create(Employee &)const;
    virtual void update(const Employee &)const;
    virtual void remove(const Employee &)const;
    Employee getById(int id)const;
    virtual std::unique_ptr<std::vector<std::unique_ptr<Employee>>> getAll()const;

    Employee getEmployeeByCode(const QString& code)const ;

protected:
    virtual void init();
};


#endif // EMPLOYEE_DAOPOSTGRES_H
