#ifndef ENTITY_H
#define ENTITY_H

#include "../bm-lib_global.h"
#include <QString>
#include <QDate>

#include "serializers/serializable.h"
#include "street.h"
#include "city.h"

class BMLIBSHARED_EXPORT Entity:public Serializable
{

public:
    Entity();
    Entity(const QVariant& variant);
    virtual ~Entity();

    //Doesn't compare the ID
    bool operator==(Entity const& e) const;
    Entity& operator=(const Entity & src);
    virtual QString toString() const;

    //From Serializable interface
    virtual QVariant toVariant() const;
    virtual void fromVariant(const QVariant& variant);



    int getId() const;
    void setId(int value);

    bool getIsDelete() const;
    void setIsDelete(bool value);

    QString getName() const;
    void setName(const QString &value);

    QString getForename() const;
    void setForename(const QString &value);

    QString getPhone() const;
    void setPhone(const QString &value);

    QString getCode() const;
    void setCode(const QString &value);

    Street getStreet() const;
    void setStreet(const Street &value);

    City getCity() const;
    void setCity(const City &value);

    QDate getBirthday() const;
    virtual void setBirthday(const QDate &value);

    QString getPicture() const;
    void setPicture(const QString &value);


protected:
    bool compare(Entity const& src) const;

private:
    int id;
    bool isDelete;
    QString name;
    QString forename;
    QString phone;
    QString code;
    Street street;
    City city;
    QDate birthday;
    QString picture;

    void init();
};

#endif // ENTITY_H
