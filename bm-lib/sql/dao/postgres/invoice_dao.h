#ifndef ORDER_DAO_H
#define ORDER_DAO_H

#include "../invoice_abstractdao.h"
class InvoiceDao : public InvoiceAbstractDao
{
public:
    InvoiceDao(QSqlDatabase &db);

    // AbstractDao interface
public:
    virtual void create(Invoice &) const;
    virtual void update(const Invoice &) const;
    virtual void remove(const Invoice &) const;
    virtual Invoice getById(int id) const;
    virtual std::unique_ptr<std::vector<std::unique_ptr<Invoice> > > getAll() const;
    virtual std::unique_ptr<std::vector<std::unique_ptr<Invoice>>> getOrdersByStakeholder(int stakeholder) const;

protected:
    virtual void init();
};
#endif // ORDER_DAO_H
