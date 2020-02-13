#ifndef ORDER_H
#define ORDER_H

#include <QDateTime>
#include <vector>
#include "serializers/serializable.h"
#include "valueObjects/compositionorder.h"
class Invoice : public Serializable
{
public:
    Invoice();
    Invoice(const QVariant& variant);
    virtual QVariant toVariant() const;
    virtual void fromVariant(const QVariant &variant);


    int getId() const;
    void setId(int value);

    int getIdStakeholder() const;
    void setIdStakeholder(int value);


    std::vector<CompositionOrder> getCompositions() const;
    void setCompositions(const std::vector<CompositionOrder> &value);



    float getPrice() const;
    void setPrice(float value);

    QDateTime getTransactionTime() const;
    void setTransactionTime(const QDateTime &value);

    bool isDeleted() const;
    void setDeleted(bool value);


private:
    int id;
    int idStakeholder;
    float price;
    QDateTime transactionTime;
    bool deleted;

    std::vector<CompositionOrder> compositions;

};



#endif // ORDER_H
