#ifndef TYPEEMPLOYEE_H
#define TYPEEMPLOYEE_H

#include "../bm-lib_global.h"
#include <QString>
#include "serializers/serializable.h"

class BMLIBSHARED_EXPORT TypeEmployee:public Serializable
{
public:
    TypeEmployee();
    TypeEmployee(const QVariant& variant);
    TypeEmployee(int id,const QString& name="");

    TypeEmployee operator=(const TypeEmployee &type);
    bool operator==(const TypeEmployee & type) const;


    // Serializable interface
    virtual QVariant toVariant() const;
    virtual void fromVariant(const QVariant &variant);

    int getId() const;
    void setId(int value);

    QString getName() const;
    void setName(const QString &value);

private:
    int id;
    QString name;

};

#endif // TYPEEMPLOYEE_H
