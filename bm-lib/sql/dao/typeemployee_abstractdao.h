#ifndef TYPEEMPLOYEE_ABSTRACTDAO_H
#define TYPEEMPLOYEE_ABSTRACTDAO_H

#include "abstractdao.h"
#include "entities/type_employee.h"
class TypeEmployeeAbstractDao : public AbstractDao<TypeEmployee>
{
public:
    TypeEmployeeAbstractDao(QSqlDatabase &db):AbstractDao(db){}
    virtual ~TypeEmployeeAbstractDao();
};

#endif // TYPEEMPLOYEE_ABSTRACTDAO_H
