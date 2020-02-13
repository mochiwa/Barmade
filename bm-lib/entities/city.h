#ifndef CITY_H
#define CITY_H

#include "../bm-lib_global.h"
#include <string>
#include "serializers/serializable.h"

class BMLIBSHARED_EXPORT City : public Serializable
{
public:
    City();
    City(int id,const QString &name="",
         const QString &cp="");
    City(const QVariant& variant);

    City& operator=(const City& src);
    bool operator==(const City& src) const;

    // Serializable interface
    virtual QVariant toVariant() const;
    virtual void fromVariant(const QVariant &variant);

    QString toString() const;

    int getId() const;
    void setId(int value);


    QString getName() const;
    void setName(const QString &value);

    QString getCp() const;
    void setCp(const QString &value);


private:
    int id;
    QString name;
    QString cp;


};


#endif // CITY_H
