#ifndef PLANNING_ABSTRACTDAO_H
#define PLANNING_ABSTRACTDAO_H

#include "abstractdao.h"
#include "entities/planning.h"

class PlanningAbstractDao: public AbstractDao<Planning>
{
public:
    PlanningAbstractDao(QSqlDatabase &db):AbstractDao(db){}
    virtual ~PlanningAbstractDao();
    virtual std::unique_ptr<std::vector<std::unique_ptr<Planning>>> getAll() const=0;
    virtual std::unique_ptr<std::vector<std::unique_ptr<Planning>>> getPlanningByEmployee(int idUser) const=0;
};

#endif // PLANNING_ABSTRACTDAO_H
