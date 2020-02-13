#ifndef PRICE_H
#define PRICE_H

#include <math.h>
#include "serializers/serializable.h"

class Price : public Serializable
{
public:
    Price(float value=0.0f);
    ~Price();

    bool operator==(const Price& p)const;
    bool operator!=(const Price& p) const;
    bool operator<(const Price& p)const;
    bool operator>(const Price& p)const;
    operator float() const;

    virtual QVariant toVariant() const;
    virtual void fromVariant(const QVariant &variant);

    float getValue() const;
    void setValue(float value);
private:
    float value;

};



#endif // PRICE_H
