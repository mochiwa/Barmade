#ifndef ABSTRACTDAO_H
#define ABSTRACTDAO_H

#include "bm-lib_global.h"
#include <memory>
#include <vector>
#include <QSqlDatabase>
#include <QSqlQuery>

template <class T>
class BMLIBSHARED_EXPORT AbstractDao
{
public:
    AbstractDao(QSqlDatabase& database):db(database){}
    virtual ~AbstractDao(){}

    virtual void create(T&)const=0;
    virtual void update(const T&)const=0;
    virtual void remove(const T&)const=0;
    virtual T getById(int id)const=0;

protected:
    virtual void init()=0;
    QSqlDatabase& db;
};

#endif // ABSTRACTDAO_H
