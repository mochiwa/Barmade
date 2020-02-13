#include "jsonserialiser.h"

JsonSerialiser::JsonSerialiser()
{
    // to change : check file
}

JsonSerialiser::~JsonSerialiser()
{

}

//------------- PRIVATE -------------//

//------------- PUBLIC -------------//

void JsonSerialiser::create(const Serializable & obj,const QString &output,const QString &root)
{
    Q_UNUSED(root);
    QJsonDocument doc = QJsonDocument::fromVariant(obj.toVariant());
    QFile file(output);
    file.open(QFile::WriteOnly);

    file.write(doc.toJson());
    file.close();
    //getLastId
}

void JsonSerialiser::read(Serializable & obj,const QString &output,const QString &root) const
{
    Q_UNUSED(root);
    QFile file(output);
    file.open(QFile::ReadOnly);
    QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
    file.close();
    obj.fromVariant(doc.toVariant());
}

void JsonSerialiser::update(Serializable &obj,const QString &output,const QString &root) const
{
    Q_UNUSED(obj);
    Q_UNUSED(output);
    Q_UNUSED(root);
}

void JsonSerialiser::del(Serializable &obj,const QString &output,const QString &root) const
{
    Q_UNUSED(obj);
    Q_UNUSED(output);
    Q_UNUSED(root);
}

//-------- Getter & Setter ---------//

