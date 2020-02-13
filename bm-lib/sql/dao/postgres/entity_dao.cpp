#include "entity_dao.h"
#include "../../database_manager.h"

EntityDao::EntityDao(QSqlDatabase &db):
    EntityAbstractDao (db)
{
    init();
}

void EntityDao::create(Entity &e) const
{
    QSqlQuery q(db);
    q.prepare("SELECT f_create_entity(:name,:forename,:birth,:phone,:picture,:id_street,:code)");
    q.bindValue(":name",e.getName());
    q.bindValue(":forename",e.getForename());
    q.bindValue(":birth",e.getBirthday());
    q.bindValue(":phone",e.getPhone());
    q.bindValue(":picture",e.getPicture());
    q.bindValue(":id_street",e.getStreet().getId());
    q.bindValue(":code",e.getCode());
    q.exec();
    if(q.next())
        e.setId(q.value(0).toInt());
}

void EntityDao::update(const Entity &e) const
{
    QSqlQuery q(db);
    q.prepare("SELECT f_update_entity(:id,:isdelete,:name,:forename,:birth,:phone,:code,:picture,:id_street)");
    q.bindValue(":id",e.getId());
    q.bindValue(":isdelete",e.getIsDelete());
    q.bindValue(":name",e.getName());
    q.bindValue(":forename",e.getForename());
    q.bindValue(":birth",e.getBirthday());
    q.bindValue(":phone",e.getPhone());
    q.bindValue(":code",e.getCode());
    q.bindValue(":picture",e.getPicture());
    q.bindValue(":id_street",e.getStreet().getId());
    q.exec();
}

void EntityDao::remove(const Entity &e) const
{
   Q_UNUSED(e);
}

Entity EntityDao::getById(int id) const
{
    Entity e;
    QSqlQuery q(db);
    q.prepare("SELECT * FROM entities WHERE id_entity=:id");
    q.bindValue(":id",id);
    q.exec();
    if(q.next())
    {
        e.setId(q.value("id_entity").toInt());
        e.setIsDelete(q.value("isDelete_entity").toBool());
        e.setName(q.value("name_entity").toString());
        e.setForename(q.value("forename_entity").toString());
        e.setPhone(q.value("phone_entity").toString());
        e.setBirthday(q.value("birthday_entity").toDate());
        e.setCode(q.value("code_entity").toString());
        e.setPicture(q.value("picture_entity").toString());
        e.setStreet(Street(q.value("id_street").toInt()));
    }
    return e;
}


void EntityDao::init()
{
}
