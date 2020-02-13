#ifndef TYPEEMPLOYE_DAO_H
#define TYPEEMPLOYE_DAO_H

#include "../typeemployee_abstractdao.h"
class TypeEmployeDao : public TypeEmployeeAbstractDao
{
public:
    TypeEmployeDao(QSqlDatabase &db);
    // AbstractDao interface
    virtual void create(TypeEmployee &) const;
    virtual void update(const TypeEmployee &) const;
    virtual void remove(const TypeEmployee &) const;
    virtual TypeEmployee getById(int id) const;
protected:
    virtual void init();
};

#endif // TYPEEMPLOYE_DAO_H
