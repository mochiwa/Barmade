#ifndef STREET_DAOPOSTGRES_H
#define STREET_DAOPOSTGRES_H

#include "../street_abstractdao.h"

class StreetDao : public StreetAbstractDao
{
public:
    StreetDao(QSqlDatabase &db);

    // AbstractDao interface
public:
    void create(Street &)const;
    void update(const Street &)const;
    void remove(const Street &)const;
    Street getById(int id)const;
    // StreetAbstractDao interface
    virtual Street getStreet_by_idEntity(int id_entity);


protected:
    virtual void init();
};





#endif // STREET_DAOPOSTGRES_H
