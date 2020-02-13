#include "employee.h"

Employee::Employee(): Entity()
{
    init();
}

Employee::Employee(const QVariant &variant):Entity(variant)
{
    fromVariant(variant);
}

Employee const& Employee::operator=(const Employee& src)
{
    if(this==&src)
        return *this;
    Entity::operator=(src);
    setSalary(src.getSalary());
    setType(src.getType());
    //setPlannings(src.getPlannings());
    return *this;
}

const Employee &Employee::operator=(const Entity &src)
{
    if(this==&src)
        return *this;
    Entity::operator=(src);
    return *this;
}

bool Employee::operator==(const Employee &e) const
{
    if(!compare(e))
        return false;
    if(!(getType()==e.getType()))
        return false;
    if((salary-e.salary)>0.00001f)
        return false;
    return true;
}

QString Employee::toString() const
{
    QString out=Entity::toString();
    out+="salary:"+QString::number(static_cast<double>(getSalary()));
    return out;
}

QVariant Employee::toVariant() const
{
    QVariantMap m=Entity::toVariant().toMap();
    QVariantList planning_Vlist;
    m.insert("type",getType().toVariant());
    m.insert("salary",salary);
    for (auto& p:plannings)
        planning_Vlist.append(p->toVariant());
    m.insert("plannings",planning_Vlist);
    return m;
}

void Employee::fromVariant(const QVariant& variant)
{
    QVariantMap m=variant.toMap();
    QList<const Planning*> plannings;
    QVariantList planning_Vlist;

    Entity::fromVariant(variant);
    type.fromVariant((m.value("type")));
    setSalary(m.value("salary").toFloat());
    planning_Vlist=m.value("plannings").toList();
    for(auto v:planning_Vlist)
    {
        Planning p;
        p.fromVariant(v);
        plannings.append(&p);
    }
    setPlannings(plannings);
}

//------------- PRIVATE -------------//

void Employee::init()
{
    setSalary(-1);
}
//------------- PUBLIC -------------//

//-------- Getter & Setter ---------//

float Employee::getSalary() const
{
    return salary;
}

void Employee::setSalary(float value)
{
    salary = value;
}

QList<const Planning *> Employee::getPlannings() const
{
    return plannings;
}

void Employee::setPlannings(const QList<const Planning *> &value)
{
    plannings = value;
}

TypeEmployee Employee::getType() const
{
    return type;
}

void Employee::setType(const TypeEmployee &value)
{
    type = value;
}
