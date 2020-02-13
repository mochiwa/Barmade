#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <QList>
#include "entity.h"
#include "type_employee.h"
#include "planning.h"

class BMLIBSHARED_EXPORT Employee : public Entity
{
public:
    Employee();
    Employee(const QVariant& variant);

    Employee const& operator=(const Employee& src);
    Employee const& operator=(const Entity& src);
    bool operator==(const Employee& e) const;
    virtual QString toString()const override ;

    //From Serializable interface
    virtual QVariant toVariant() const override;
    virtual void fromVariant(const QVariant& variant) override;

    //getter and setter
    float getSalary() const;
    void setSalary(float value);

    QList<const Planning*> getPlannings() const;
    void setPlannings(const QList<const Planning *> &value);

    TypeEmployee getType() const;
    void setType(const TypeEmployee &value);

private:
    float salary;
    TypeEmployee type;
    QList<const Planning*> plannings;

    void init();
};

#endif // EMPLOYEE_H
