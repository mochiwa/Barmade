#ifndef EMPLOYEEBUILDER_H
#define EMPLOYEEBUILDER_H

#include "abstractbuilder.h"
#include "entities/employee.h"
#include "entitybuilder.h"
#include <vector>
#include <memory>

class EmployeeBuilder : public AbstractBuilder<Employee>
{
public:
    static EmployeeBuilder getInstance();
    void build(Employee& e)const;
    void update(Employee& e)const;
    void load(Employee& e)const;
    std::unique_ptr<std::vector<std::unique_ptr<Employee>>> getAll();
protected:
    EmployeeBuilder();
};

#endif // EMPLOYEEBUILDER_H
