#ifndef COMPOSITIONORDER_ABSTRACTDAO_H
#define COMPOSITIONORDER_ABSTRACTDAO_H

#include "abstractdao.h"
#include "valueObjects/compositionorder.h"

class CompositionOrderAbstractDao : public AbstractDao<CompositionOrder>
{
public:
    CompositionOrderAbstractDao(QSqlDatabase &db):AbstractDao(db){}
    virtual  ~CompositionOrderAbstractDao();

    virtual std::vector<CompositionOrder> getByOrder(int idOrder) const=0;


};

#endif // COMPOSITIONORDER_ABSTRACTDAO_H
