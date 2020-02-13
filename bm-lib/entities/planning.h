#ifndef PLANNING_H
#define PLANNING_H

#include "../bm-lib_global.h"
#include <QString>

#include "serializers/serializable.h"
#include <QDateTime>


class BMLIBSHARED_EXPORT Planning : public Serializable
{
public:
    Planning();
    Planning(int id,
             QDateTime const& begin=QDateTime::currentDateTime(),
             QDateTime const& end=QDateTime::currentDateTime(),
             QString const& comment="",
             bool isDayOff=true,
             int idOwner=-1,
             bool isDelete=false);
    Planning(const QVariant& variant);

    Planning& operator=(const Planning& src);
    bool operator==(const Planning& src);

    //From Serializable interface
    virtual QVariant toVariant() const;
    virtual void fromVariant(const QVariant& variant);

    QString toString();

    int getId() const;
    void setId(int value);

    QDateTime getBegin() const;
    void setBegin(const QDateTime &value);
    void setBegin(const QDate &value);
    void setBegin(const QTime &value);

    QDateTime getEnd() const;
    void setEnd(const QDateTime &value);
    void setEnd(const QDate &value);
    void setEnd(const QTime &value);

    QString getComment() const;
    void setComment(const QString &value);

    int getIdOwner() const;
    void setIdOwner(int value);

    bool getIsDayOff() const;
    void setIsDayOff(bool value);

    bool getIsDelete() const;
    void setIsDelete(bool value);

private:
    int id;
    bool isDelete;
    int idOwner;
    QDateTime begin;
    QDateTime end;
    QString comment;
    bool isDayOff;
};

#endif // PLANNING_H
