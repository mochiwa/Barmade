#ifndef ORDER_ABSTRACTDAO_H
#define ORDER_ABSTRACTDAO_H
#include "abstractdao.h"
#include "entities/invoice.h"

class InvoiceAbstractDao : public AbstractDao<Invoice>
{
public:
    InvoiceAbstractDao(QSqlDatabase &db):AbstractDao(db){}
    virtual ~InvoiceAbstractDao();

    virtual std::unique_ptr<std::vector<std::unique_ptr<Invoice>>> getAll()const=0;
    virtual std::unique_ptr<std::vector<std::unique_ptr<Invoice>>> getOrdersByStakeholder(int stakeholder) const=0;
};

#endif // ORDER_ABSTRACTDAO_H
