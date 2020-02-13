#ifndef SERIALIZER_H
#define SERIALIZER_H

#include "../bm-lib_global.h"
#include "serializable.h"
#include <QVariant>
#include <QVariantMap>

class BMLIBSHARED_EXPORT Serializer
{

public:
    Serializer();
    virtual ~Serializer();

    virtual void create(const Serializable & obj,const QString &filepath,const QString &root="")=0;
    virtual void read(Serializable & obj,const QString &filepath,const QString &root="") const=0;
    virtual void update(Serializable &obj,const QString &filepath,const QString &root="") const=0;
    virtual void del(Serializable &obj,const QString &filepath,const QString &root="")const=0;

    int getLastId() const;
    void setLastId(int value);

protected:
    int lastId;
};

#endif // SERIALIZER_H
