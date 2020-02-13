#include "street.h"

Street::Street()
{
    setId(-1);
    setName("");
    setNumber("");
    setId_city(-1);
}
Street::Street(int id,const QString& name,const QString& number,int id_city):
    Street()
{
    setId(id);
    setName(name);
    setNumber(number);
    setId_city(id_city);
}

Street::Street(const QVariant &variant)
{
    fromVariant(variant);
}

Street& Street::operator=(const Street& src)
{
    if(&src==this)
        return *this;
    setId(src.getId());
    setNumber(src.getNumber());
    setName(src.getName());
    setId_city(src.getId_city());
    return *this;
}

bool Street::operator==(const Street& src) const
{
    if(id!=src.getId())
        return false;
    if(id_city!=src.getId_city())
        return false;
    if(number.compare(src.getNumber()))
        return false;
    if(name.compare(src.getName()))
        return false;
    return true;
}

QVariant Street::toVariant() const
{
    QVariantMap m;
    m.insert("id",getId());
    m.insert("id_city",getId_city());
    m.insert("street",getName());
    m.insert("number",getNumber());
    return m;
}

void Street::fromVariant(const QVariant &variant)
{
    QVariantMap m=variant.toMap();
    setId(m.value("id").toInt());
    setId_city(m.value("id_city").toInt());
    setName(m.value("street").toString());
    setNumber(m.value("number").toString());
}

QString Street::toString() const
{
    QString out="";
    out+="[STREET] id: "+QString::number(getId())+" id_city: "+QString::number(getId_city())+
            "name :"+getName()+" number"+getNumber();
    return out;

}

int Street::getId() const
{
    return id;
}

void Street::setId(int value)
{
    id = value;
}

QString Street::getName() const
{
    return name;
}

void Street::setName(const QString &value)
{
    name = value;
}

QString Street::getNumber() const
{
    return number;
}

void Street::setNumber(const QString &value)
{
    number = value;
}

int Street::getId_city() const
{
    return id_city;
}

void Street::setId_city(int value)
{
    id_city = value;
}
