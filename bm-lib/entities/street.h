#ifndef STREET_H
#define STREET_H

#include "../bm-lib_global.h"
#include <string>
#include "serializers/serializable.h"
class BMLIBSHARED_EXPORT Street: public Serializable
{
public:
    Street();
    Street(int id,const QString& name="",const QString& number="",int id_city=-1);
    Street(const QVariant& variant);

    Street& operator=(const Street& src);
    bool operator==(const Street& src) const;

    // Serializable interface
    virtual QVariant toVariant() const;
    virtual void fromVariant(const QVariant &variant);

    QString toString()const;

    int getId() const;
    void setId(int value);

    QString getName() const;
    void setName(const QString &value);

    QString getNumber() const;
    void setNumber(const QString &value);

    int getId_city() const;
    void setId_city(int value);

private:
    int id;
    int id_city;
    QString name;
    QString number;
};



#endif // STREET_H
