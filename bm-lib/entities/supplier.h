#ifndef SUPPLIER_H
#define SUPPLIER_H

#include "entity.h"

class BMLIBSHARED_EXPORT Supplier : public Entity
{
public:
    Supplier();
    Supplier(QString const& fax,QString const& society);

    Supplier &operator=(const Supplier& src);
    bool operator==(const Supplier& s) const;

    //From Serializable interface
    virtual QVariant toVariant() const;
    virtual void fromVariant(const QVariant &variant);

    QString getFax() const;
    void setFax(const QString &value);

    QString getCompany() const;
    void setCompany(const QString &value);

    void setBirthday(const QDate& value);

private:
    QString fax;
    QString company;


};
#endif // SUPPLIER_H
