#include "capacity.h"

Capacity::Capacity(float value):value(value)
{
}

Capacity::Capacity(const QVariant &variant)
{
    fromVariant(variant);
}

Capacity::~Capacity()
{

}

bool Capacity::operator==(const Capacity& c)const
{
    return !(fabs(value-c.value)>0.0000000005f);
}
bool Capacity::operator!=(const Capacity& c) const
{
    return !(*this==c);
}
bool Capacity::operator<(const Capacity& c)const
{
    return value<c.value;
}
bool Capacity::operator>(const Capacity& c)const
{
    return value>c.value;
}

Capacity::operator float() const
{
    return value;
}


QVariant Capacity::toVariant() const
{
    QVariantMap m;
    m.insert("value",value);
    return m;
}
void Capacity::fromVariant(const QVariant &variant)
{
    QVariantMap m=variant.toMap();
    value=m.value("value").toFloat();
}

float Capacity::getValue() const
{
    return value;
}

void Capacity::setValue(float value)
{
    this->value = value;
}
