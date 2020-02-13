#include "supplier.h"

using namespace std;

Supplier::Supplier()
{
    setFax("");
    setCompany("");
}

Supplier::Supplier(const QString &fax, const QString &company):
    Supplier()
{
    setFax(fax);
    setCompany(company);
}

Supplier &Supplier::operator=(const Supplier &src)
{
    if(this==&src)
        return *this;
    Entity::operator=(src);
    setFax(src.fax);
    setCompany(src.company);
    return *this;
}

bool Supplier::operator==(const Supplier &s) const
{
    if(!s.compare(*this))
        return false;
    if(fax.compare(s.fax))
        return false;
    if(company.compare(s.company))
        return false;
    return true;
}

QVariant Supplier::toVariant() const
{
    QVariantMap map=Entity::toVariant().toMap();
    map.insert("fax",getFax());
    map.insert("company",getCompany());
    return map;
}

void Supplier::fromVariant(const QVariant &variant)
{
    QVariantMap map=variant.toMap();
    Entity::fromVariant(variant);
    setFax(map.value("fax").toString());
    setCompany(map.value("company").toString());
}

QString Supplier::getFax() const
{
    return fax;
}

void Supplier::setFax(const QString &value)
{
    fax = value;
}

QString Supplier::getCompany() const
{
    return company;
}

void Supplier::setCompany(const QString &value)
{
    company = value;
}

void Supplier::setBirthday(const QDate &value)
{
    if(value.isValid())
        Entity::setBirthday(value);
    else
        Entity::setBirthday(QDate::currentDate());
}
