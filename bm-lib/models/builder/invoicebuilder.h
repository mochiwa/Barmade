#ifndef ORDERBUILDER_H
#define ORDERBUILDER_H

#include "abstractbuilder.h"
#include "entities/invoice.h"
#include <vector>
#include <memory>
class InvoiceBuilder : public AbstractBuilder<Invoice>
{
public:
    static InvoiceBuilder getInstance();
    void build(Invoice& o)const;
    void update(Invoice& o)const;
    void load(Invoice& o)const;
    std::unique_ptr<std::vector<std::unique_ptr<Invoice>>> getByStakeholder(int id);
protected:
    InvoiceBuilder();
};

#endif // ORDERBUILDER_H
