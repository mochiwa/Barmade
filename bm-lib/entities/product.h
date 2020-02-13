#ifndef PRODUCT_H
#define PRODUCT_H

#include "bm-lib_global.h"
#include <QString>
#include <vector>
#include "serializers/serializable.h"
#include "valueObjects/price.h"
#include "valueObjects/capacity.h"
#include "valueObjects/ingredient.h"

class BMLIBSHARED_EXPORT Product : public Serializable
{
public:
    Product();
    Product(const QVariant& variant);
    bool operator==(const Product& p)const ;
    Product& operator=(const Product& src);
    bool operator<(const Product &) const;

    //From Serializable interface
    virtual QVariant toVariant() const;
    virtual void fromVariant(const QVariant& variant);

    int getId() const;
    void setId(int value);

    bool getIsDelete() const;
    void setIsDelete(bool value);

    QString getName() const;
    void setName(const QString &value);

    QString getPicture() const;
    void setPicture(const QString &value);

    Price getPrice() const;
    void setPrice(float value);

    int getStock() const;
    void setStock(int value);

    Capacity getCapacity() const;
    void setCapacity(const float &value);

    Capacity getUsed() const;
    void setUsed(const Capacity &value);

    int getAlarm() const;
    void setAlarm(int value);

    std::vector<Ingredient> getIngredients() const;
    void setIngredients(const std::vector<Ingredient> &value);

private:
    int id;
    bool isDelete;
    int stock;
    int alarm;
    QString name;
    QString picture;

    Price price;
    Capacity capacity;
    Capacity used;
    std::vector<Ingredient> ingredients;
};

#endif // PRODUCT_H
