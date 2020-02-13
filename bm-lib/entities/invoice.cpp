#include "invoice.h"

using namespace std;
Invoice::Invoice()
{
    setId(-1);
    setIdStakeholder(-1);
    setPrice(0);
    setTransactionTime(QDateTime::currentDateTime());
    setDeleted(false);
}

Invoice::Invoice(const QVariant &variant)
{
    fromVariant(variant);
}

QVariant Invoice::toVariant() const
{
    QVariantMap m;
    QVariantList list;
    m.insert("id",getId());
    m.insert("stakeholder",getIdStakeholder());
    m.insert("time",getTransactionTime());
    m.insert("price",getPrice());
    m.insert("deleted",isDeleted());
    for(auto const& c:compositions)
        list.push_back(c.toVariant());
    m.insert("compositions",list);
    return m;
}
void Invoice::fromVariant(const QVariant &variant)
{
    QVariantMap m=variant.toMap();
    QVariantList l=m.value("compositions").toList();

    vector<CompositionOrder> compositions;
    setId(m.value("id").toInt());
    setIdStakeholder(m.value("stakeholder").toInt());
    setTransactionTime(m.value("time").toDateTime());
    setPrice(m.value("price").toFloat());
    setDeleted(m.value("deleted").toBool());
    for(auto const&c:l)
    {
        CompositionOrder toAppend;
        toAppend.fromVariant(c);
        compositions.push_back(toAppend);
    }
    setCompositions(compositions);

}
int Invoice::getId() const
{
    return id;
}

void Invoice::setId(int value)
{
    id = value;
}

std::vector<CompositionOrder> Invoice::getCompositions() const
{
    return compositions;
}

void Invoice::setCompositions(const std::vector<CompositionOrder> &value)
{
    compositions = value;
}

float Invoice::getPrice() const
{
    return price;
}

void Invoice::setPrice(float value)
{
    price = value;
}

QDateTime Invoice::getTransactionTime() const
{
    return transactionTime;
}

void Invoice::setTransactionTime(const QDateTime &value)
{
    transactionTime = value;
}

bool Invoice::isDeleted() const
{
    return deleted;
}

void Invoice::setDeleted(bool value)
{
    deleted = value;
}

int Invoice::getIdStakeholder() const
{
    return idStakeholder;
}

void Invoice::setIdStakeholder(int value)
{
    idStakeholder = value;
}
