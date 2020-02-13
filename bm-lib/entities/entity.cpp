#include "entity.h"

Entity::Entity()
{
    init();
}

Entity::Entity(const QVariant &variant)
{
    fromVariant(variant);
}

Entity::~Entity()
{
}

//------------- PRIVATE -------------//
void Entity::init()
{
    setId(-1);
    setIsDelete(false);
    setCode("");
    setName("");
    setForename("");
    setBirthday(QDate::currentDate());
    setPhone("");
    setPicture("");
    setStreet(Street());
    setCity(City());
}

//------------- PUBLIC -------------//

Entity& Entity::operator=(const Entity & src)
{
    if(this==&src)
        return *this;

    setId(src.getId());
    setIsDelete(src.getIsDelete());
    setCode(src.getCode());
    setName(src.getName());
    setForename(src.getForename());
    setBirthday(src.getBirthday());
    setPhone(src.getPhone());
    setStreet(src.getStreet());
    setCity(src.getCity());
    setPicture(src.getPicture());
    return *this;
}

bool Entity::operator==(const Entity &e) const
{
    if(isDelete!=e.isDelete)
        return false;
    if(code.compare(e.code))
        return false;
    if(name.compare(e.name))
        return false;
    if(forename.compare(e.forename))
        return false;
    if(birthday!=e.birthday)
        return false;
    if(phone.compare(e.phone))
        return false;
    if(!(street==e.street))
        return false;
    if(!(city==e.city))
        return false;
    if(picture.compare(e.picture))
        return false;
    return true;
}

QString Entity::toString() const
{
    QString out="id :"+QString::number(getId())+"\n"+
            "isDelete"+getIsDelete()+"\n"+
            "code :"+getCode()+"\n"+
            "name :"+getName()+"\n"+
            "forename :"+getForename()+"\n"+
            "birthday :"+getBirthday().toString("dd-mm-yyyy");
            "phone :"+getPhone()+"\n"+
            city.toString()+
            street.toString();
    return out;
}

QVariant Entity::toVariant() const
{
    QVariantMap m;
    m.insert("id",id);
    m.insert("isDelete",isDelete);
    m.insert("code",code);
    m.insert("name",name);
    m.insert("forename",forename);
    m.insert("birthday",birthday);
    m.insert("phone",phone);
    m.insert("street",street.toVariant());
    m.insert("city",city.toVariant());
    m.insert("picture",picture);
    return m;
}

void Entity::fromVariant(const QVariant& variant)
{
    QVariantMap m=variant.toMap();
    setId(m.value("id").toInt());
    setIsDelete(m.value("isDelete").toBool());
    setCode(m.value("code").toString());
    setName(m.value("name").toString());
    setForename(m.value("forename").toString());
    setBirthday(m.value("birthday").toDate());
    setPhone(m.value("phone").toString());
    street.fromVariant(m.value("street"));
    city.fromVariant(m.value("city"));
    setPicture(m.value("picture").toString());
}

bool Entity::compare(const Entity &src) const
{
    return this->operator==(src);
}

//-------- Getter & Setter ---------//
City Entity::getCity() const
{
    return city;
}

void Entity::setCity(const City &value)
{
    city = value;
}

Street Entity::getStreet() const
{
    return street;
}

void Entity::setStreet(const Street &value)
{
    street = value;
}

QString Entity::getPicture() const
{
    return picture;
}

void Entity::setPicture(const QString &value)
{
    picture = value;
}

QDate Entity::getBirthday() const
{
    return birthday;
}

void Entity::setBirthday(const QDate &value)
{
    birthday=value;
}

int Entity::getId() const
{
    return id;
}

void Entity::setId(int value)
{
    id = value;
}

bool Entity::getIsDelete() const
{
    return isDelete;
}

void Entity::setIsDelete(bool value)
{
    isDelete = value;
}

QString Entity::getName() const
{
    return name;
}

void Entity::setName(const QString &value)
{
    name = value;
}

QString Entity::getForename() const
{
    return forename;
}

void Entity::setForename(const QString &value)
{
    forename = value;
}

QString Entity::getPhone() const
{
    return phone;
}

void Entity::setPhone(const QString &value)
{
    phone = value;
}

QString Entity::getCode() const
{
    return code;
}

void Entity::setCode(const QString &value)
{
    code = value;
}
