#ifndef JSONSERIALISER_H
#define JSONSERIALISER_H

#include "serializer.h"
#include <QJsonDocument>
#include <QFile>

class JsonSerialiser : public Serializer
{
public:
    JsonSerialiser();
    virtual ~JsonSerialiser();
    virtual void create(const Serializable & obj,const QString &output,const QString &root="");
    virtual void read(Serializable & obj,const QString &output,const QString &root="")const;
    virtual void update(Serializable &obj,const QString &output,const QString &root="")const;
    virtual void del(Serializable &obj,const QString &output,const QString &root="")const;
};

#endif // JSONSERIALISER_H
