#include "type_employee.h"

TypeEmployee::TypeEmployee()
{
    setId(-1);
    setName("");
}

TypeEmployee::TypeEmployee(const QVariant &variant)
{
    fromVariant(variant);
}

TypeEmployee::TypeEmployee(int id,const QString& name)
{
    setId(id);
    setName(name);
}

TypeEmployee TypeEmployee::operator=(const TypeEmployee &type)
{
    if(this==&type)
        return *this;
    setId(type.getId());
    setName(type.getName());
    return *this;
}

bool TypeEmployee::operator==(const TypeEmployee & type) const
{
    if(id!=type.getId())
        return false;
    if(name.compare(type.getName()))
        return false;
    return true;
}

//------------- PRIVATE -------------//

//------------- PUBLIC -------------//

QVariant TypeEmployee::toVariant() const
{
    QVariantMap m;
    m.insert("id",getId());
    m.insert("name",getName());
    return m;
}

void TypeEmployee::fromVariant(const QVariant &variant)
{
    QVariantMap m=variant.toMap();
    setId(m.value("id").toInt());
    setName(m.value("name").toString());
}
//-------- Getter & Setter ---------//

int TypeEmployee::getId() const
{
    return id;
}

void TypeEmployee::setId(int value)
{
    id = value;
}

QString TypeEmployee::getName() const
{
    return name;
}

void TypeEmployee::setName(const QString &value)
{
    name = value;
}
