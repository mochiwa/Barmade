#ifndef PLANNING_DAO_H
#define PLANNING_DAO_H

#include "../planning_abstractdao.h"

class PlanningDao : public PlanningAbstractDao
{
public:
    PlanningDao(QSqlDatabase &db);
    
    // AbstractDao interface
public:
    virtual void create(Planning &) const;
    virtual void update(const Planning &) const;
    virtual void remove(const Planning &) const;
    virtual Planning getById(int id) const;
    virtual std::unique_ptr<std::vector<std::unique_ptr<Planning>>> getAll() const;
    std::unique_ptr<std::vector<std::unique_ptr<Planning>>> getPlanningByEmployee(int idUser)const;
protected:
    virtual void init();
};



#endif // PLANNING_DAO_H
