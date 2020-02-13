#include "city.h"

City::City()
{
    setId(-1);
    setName("");
    setCp("");
}

City::City(int id,const QString &name, const QString &cp):
    City()
{
    setId(id);
    setName(name);
    setCp(cp);
}

City::City(const QVariant &variant)
{
    fromVariant(variant);
}

City &City::operator=(const City &src)
{
    if(&src==this)
        return *this;
    setId(src.getId());
    setName(src.getName());
    setCp(src.getCp());
    return *this;
}

bool City::operator==(const City& src) const
{
    if(id!=src.id)
        return false;
    if(name.compare(src.name))
        return false;
    if(cp.compare(src.cp))
        return false;
    return true;
}

QVariant City::toVariant() const
{
    QVariantMap m;
    m.insert("id",getId());
    m.insert("city",getName());
    m.insert("cp",getCp());
    return m;
}

void City::fromVariant(const QVariant &variant)
{
    QVariantMap m=variant.toMap();
    setId(m.value("id").toInt());
    setName(m.value("city").toString());
    setCp(m.value("cp").toString());
}

QString City::toString() const
{
    QString out="";
    out+="[CITY] id: "+QString::number(getId())+ "City: "+getName()+" Cp:"+getCp();
    return  out;
}


int City::getId() const
{
    return id;
}

void City::setId(int value)
{
    id = value;
}

QString City::getCp() const
{
    return cp;
}

void City::setCp(const QString &value)
{
    cp = value;
}

QString City::getName() const
{
    return name;
}

void City::setName(const QString &value)
{
    name = value;
}
