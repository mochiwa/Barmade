#ifndef COMPOSITIONORDER_DAO_H
#define COMPOSITIONORDER_DAO_H

#include "../compositionorder_abstractdao.h"

class CompositionOrderDao : public CompositionOrderAbstractDao
{
public:
    CompositionOrderDao(QSqlDatabase &db);

    virtual void create(CompositionOrder &) const;
    virtual void update(const CompositionOrder &) const;
    virtual void remove(const CompositionOrder &) const;
    virtual CompositionOrder getById(int id) const;
    virtual std::vector<CompositionOrder> getByOrder(int idOrder) const;


protected:
    virtual void init();
};



#endif // COMPOSITIONORDER_DAO_H
