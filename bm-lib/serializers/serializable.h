#ifndef SERIALIZABLE_H
#define SERIALIZABLE_H

#include "../bm-lib_global.h"
#include <QObject>
#include <QVariant>

//Abstract class
class BMLIBSHARED_EXPORT Serializable
{
public:
    Serializable();
    virtual ~Serializable();
    virtual QVariant toVariant() const = 0;
    virtual void fromVariant(const QVariant& variant) = 0;
};

#endif // SERIALIZABLE_H
