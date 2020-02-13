#ifndef DATETIME_H
#define DATETIME_H

#include "../bm-lib_global.h"
#include <ctime>

#include "serializers/serializable.h"


/**
 * MONTH : 1 -> 12
 * DAYS : 1 -> 31
 * HOURS : 0 -> 23
 * Min/sec: 0 -> 59
 */


class BMLIBSHARED_EXPORT DateTime : public Serializable
{

public:
    DateTime();
    DateTime(int day,
             int month,
             int year);

    DateTime const& now();
    DateTime const& operator=(DateTime const& src);
    //doesn't compare id
    bool operator==(DateTime const& d)const;

    // Serializable interface
    virtual QVariant toVariant() const;
    virtual void fromVariant(const QVariant &variant);

    int getYear() const;
    void setYear(int value);

    int getMonth() const;
    void setMonth(int value);

    int getDay() const;
    void setDay(int value);

    int getHour() const;
    void setHour(int value);

    int getMinute() const;
    void setMinute(int value);

    int getSec() const;
    void setSec(int value);

private:
    enum limit{YEAR_MIN=1900,
               MONTH_MIN=1,MONTH_MAX=12,
               DAY_MIN=1,DAY_MAX=31,
               HOUR_MIN=1,HOUR_MAX=23,
               MIN_MIN=0,MIN_MAX=59,
               SEC_MIN=0,SEC_MAX=59};

    int year;
    int month;
    int day;
    int hour;
    int minute;
    int sec;

    void init();

};
#endif // DATETIME_H
