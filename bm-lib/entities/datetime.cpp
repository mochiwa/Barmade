#include "datetime.h"

using namespace std;

DateTime::DateTime()
{
    init();
}

DateTime::DateTime(int day,int month,int year)
{
    init();
    setYear(year);
    setMonth(month);
    setDay(day);
}

//------------- PRIVATE -------------//
void DateTime::init()
{
    year=0;
    month=0;
    day=0;
    hour=0;
    minute=0;
    sec=0;
}
//------------- PUBLIC -------------//
DateTime const& DateTime::now()
{
    time_t timer;
    struct tm * today;
    time(&timer);
    today=std::localtime(&timer);

    setYear(today->tm_year+YEAR_MIN);
    setMonth(today->tm_mon+1);
    setDay(today->tm_mday);

    setHour(today->tm_hour);
    setMinute(today->tm_min);
    setSec(today->tm_sec);
    return *this;
}

DateTime const& DateTime::operator=(DateTime const& src)
{
    if(&src==this)
        return *this;
    setYear(src.getYear());
    setMonth(src.getMonth());
    setDay(src.getDay());
    setHour(src.getHour());
    setMinute(src.getMinute());
    setSec(src.getSec());
    return *this;
}

bool DateTime::operator==(DateTime const& d) const
{
    if(year!=d.year)
        return false;
    if(month!=d.month)
        return false;
    if(day!=d.day)
        return false;
    if(hour!=d.hour)
        return false;
    if(minute!=d.minute)
        return false;
    if(sec!=d.sec)
        return false;
    return true;
}

QVariant DateTime::toVariant() const
{
    QVariantMap m;
    m.insert("sec",getSec());
    m.insert("minute",getMinute());
    m.insert("hour",getHour());
    m.insert("day",getDay());
    m.insert("month",getMonth());
    m.insert("year",getYear());
    return m;
}

void DateTime::fromVariant(const QVariant &variant)
{
    QVariantMap m=variant.toMap();
    setSec(m.value("sec").toInt());
    setMinute(m.value("minute").toInt());
    setHour(m.value("hour").toInt());
    setDay(m.value("day").toInt());
    setMonth(m.value("month").toInt());
    setYear(m.value("year").toInt());
}


//-------- Getter & Setter ---------//

int DateTime::getYear() const
{
    return year;
}

void DateTime::setYear(int value)
{
    if(value>=YEAR_MIN)
        year = value;
}

int DateTime::getMonth() const
{
    return month;
}

void DateTime::setMonth(int value)
{
    if(value>=MONTH_MIN && value<=MONTH_MAX)
        month = value;
}

int DateTime::getDay() const
{
    return day;
}

void DateTime::setDay(int value)
{
    if(value>= DAY_MIN && value<= DAY_MAX)
        day = value;
}

int DateTime::getHour() const
{
    return hour;
}

void DateTime::setHour(int value)
{
    if(value>= HOUR_MIN && value<= HOUR_MAX)
        hour = value;
}

int DateTime::getMinute() const
{
    return minute;
}

void DateTime::setMinute(int value)
{
    if(value>=MIN_MIN && value<=MIN_MAX)
        minute = value;
}

int DateTime::getSec() const
{
    return sec;
}

void DateTime::setSec(int value)
{
    if(value>=SEC_MIN && value<=SEC_MAX)
        sec = value;
}
