#include "price.h"

Price::Price(float value):value (value)
{
}

Price::~Price()
{

}


bool Price::operator==(const Price& p)const
{
    return !(fabs(value-p.value)>0.0000000005f);
}
bool Price::operator!=(const Price& p) const
{
    return !(*this==p);
}
bool Price::operator<(const Price& p)const
{
    return value<p.value;
}
bool Price::operator>(const Price& p)const
{
    return value>p.value;
}

Price::operator float() const
{
    return value;
}

QVariant Price::toVariant() const
{
    QVariantMap m;
    m.insert("value",value);
    return m;
}
void Price::fromVariant(const QVariant &variant)
{
    QVariantMap m=variant.toMap();
    value=m.value("value").toFloat();
}

//-------- Getter & Setter ---------//

float Price::getValue() const
{
    return value;
}

void Price::setValue(float value)
{
    this->value = value;
}
