#ifndef ABSTRACTBUILDER_H
#define ABSTRACTBUILDER_H
#include "sql/database_manager.h"

template<class T>
class AbstractBuilder
{
public:
    AbstractBuilder():db(DatabaseManager::getInstance()){}
    virtual ~AbstractBuilder(){}

    //recup les donnée en bdd et les mes sur T
    virtual void build(T&)const=0;
    //place en bdd les data de T
    virtual void update(T&)const=0;
    //load from db
    virtual void load(T&)const=0;

protected:
    DatabaseManager& db;
};

#endif // ABSTRACTBUILDER_H
