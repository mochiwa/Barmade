#ifndef CAPACITY_H
#define CAPACITY_H

#include <math.h>
#include "serializers/serializable.h"

class Capacity : public Serializable
{
public:
    Capacity(float value=0.0f);
    Capacity(const QVariant& variant);
    ~Capacity();

    bool operator==(const Capacity& c)const;
    bool operator!=(const Capacity& c) const;
    bool operator<(const Capacity& c)const;
    bool operator>(const Capacity& c)const;
    operator float() const;

    virtual QVariant toVariant() const;
    virtual void fromVariant(const QVariant &variant);

    float getValue() const;
    void setValue(float value);

private:
    float value;
};


#endif // CAPACITY_H
