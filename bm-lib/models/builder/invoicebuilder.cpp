#include "invoicebuilder.h"
using namespace std;
InvoiceBuilder::InvoiceBuilder()
{
}

InvoiceBuilder InvoiceBuilder::getInstance()
{
    InvoiceBuilder builder;
    return builder;
}
void InvoiceBuilder::build(Invoice& o)const
{
    vector<CompositionOrder> compositions=o.getCompositions();
    db.orderDao->create(o);

    for(auto& c:compositions)
    {
        c.setIdOrder(o.getId());
        db.compositionOrderDao->create(c);
    }
    o.setCompositions(compositions);
}

void InvoiceBuilder::update(Invoice& o)const
{
    vector<CompositionOrder> compositions=o.getCompositions();
    db.orderDao->update(o);
    for(auto& c:compositions)
        db.compositionOrderDao->update(c);
}
void InvoiceBuilder::load(Invoice& o)const
{
    vector<CompositionOrder> compositions=db.compositionOrderDao->getByOrder(o.getId());
     o.setCompositions(compositions);
}

unique_ptr<vector<unique_ptr<Invoice>>> InvoiceBuilder::getByStakeholder(int id)
{
    unique_ptr<vector<unique_ptr<Invoice>>> orders(db.orderDao->getOrdersByStakeholder(id));

    for(unsigned int i=0;i<orders->size();++i)
    {
        vector<CompositionOrder> compositions;
        compositions=db.compositionOrderDao->getByOrder(orders->at(i)->getId());
        orders->at(i)->setCompositions(compositions);
    }
    return orders;
}
