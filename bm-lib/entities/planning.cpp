#include "planning.h"

Planning::Planning()
{
    setId(-1);
    setIsDelete(false);
    setBegin(QDate::currentDate());
    setEnd(QDate::currentDate());
    setComment("");
    setIsDayOff(true);
    setIdOwner(-1);
}

Planning::Planning(int id,
         QDateTime const& begin,
         QDateTime const& end,
         QString const& comment,
         bool isDayOff,
         int idOwner,
         bool isDelete):
    Planning()
{
    setId(id);
    setBegin(begin);
    setEnd(end);
    setComment(comment);
    setIsDayOff(isDayOff);
    setIdOwner(idOwner);
    setIsDelete(isDelete);
}

Planning::Planning(const QVariant &variant)
{
    fromVariant(variant);
}

Planning &Planning::operator=(const Planning &src)
{
    if(this==&src)
        return *this;
    setId(src.getId());
    setIsDelete(src.getIsDelete());
    setBegin(src.getBegin());
    setEnd(src.getEnd());
    setComment(src.getComment());
    setIsDayOff(src.getIsDayOff());
    setIdOwner(src.getIdOwner());
    return *this;
}

bool Planning::operator==(const Planning &src)
{
    if(id!=src.id)
        return false;
    if(isDelete!=src.getIsDelete())
        return false;
    if(begin!=src.begin)
        return false;
    if(end!=src.end)
        return false;
    if(comment.compare(src.comment))
        return false;
    if(isDayOff!=src.isDayOff)
        return false;
    if(idOwner!=src.idOwner)
        return false;
    return true;
}

QVariant Planning::toVariant() const
{
    QVariantMap m;
    m.insert("id",getId());
    m.insert("isDelete",getIsDelete());
    m.insert("begin",getBegin());
    m.insert("end",getEnd());
    m.insert("comment",getComment());
    m.insert("isDayOff",getIsDayOff());
    m.insert("idOwner",getIdOwner());
    return m;
}

void Planning::fromVariant(const QVariant& variant)
{
    QVariantMap m=variant.toMap();
    setId(m.value("id").toInt());
    setIsDelete(m.value("isDelete").toBool());
    setBegin(m.value("begin").toDateTime());
    setEnd(m.value("end").toDateTime());
    setComment(m.value("comment").toString());
    setIsDayOff(m.value("isDayOff").toBool());
    setIdOwner(m.value("idOwner").toInt());
}

QString Planning::toString()
{
    QString out="Planning ("+QString::number(id)+")\n";
    out+="Begin :" + getBegin().toString()+"\n";
    out+="End :" +getEnd().toString()+"\n";
    out+="Comments: "+getComment()+"\n";
    out+="DayOf :"+QString::number(getIsDayOff())+"\n";
    out+="owner :"+ QString::number(getIdOwner())+"\n";
    return out;
}

int Planning::getId() const
{
    return id;
}

void Planning::setId(int value)
{
    id = value;
}

QDateTime Planning::getBegin() const
{
    return begin;
}

void Planning::setBegin(const QDateTime &value)
{
    begin = value;
}

void Planning::setBegin(const QDate &value)
{
    begin.setDate(value);
}

void Planning::setBegin(const QTime &value)
{
    begin.setTime(value);
}

QDateTime Planning::getEnd() const
{
    return end;
}

void Planning::setEnd(const QDateTime &value)
{
    end = value;
}

void Planning::setEnd(const QDate &value)
{
    end.setDate(value);
}

void Planning::setEnd(const QTime &value)
{
    end.setTime(value);
}

QString Planning::getComment() const
{
    return comment;
}

void Planning::setComment(const QString &value)
{
    comment = value;
}

int Planning::getIdOwner() const
{
    return idOwner;
}

void Planning::setIdOwner(int value)
{
    idOwner = value;
}

bool Planning::getIsDayOff() const
{
    return isDayOff;
}

void Planning::setIsDayOff(bool value)
{
    isDayOff = value;
}

bool Planning::getIsDelete() const
{
    return isDelete;
}

void Planning::setIsDelete(bool value)
{
    isDelete = value;
}
