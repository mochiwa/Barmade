#include "product.h"

Product::Product()
{
    setId(-1);
    setIsDelete(false);
    setName("");
    setPicture("");
    setPrice(0);
    setStock(0);
    setCapacity(0);
    setUsed(0);
    setAlarm(0);
}

Product::Product(const QVariant &variant)
{
    fromVariant(variant);
}

bool Product::operator==(const Product& p)const
{
    if(id!=p.getId())
        return false;
    if(isDelete!=p.getIsDelete())
        return false;
    if(name.compare(p.getName()))
        return false;
    if(picture.compare(p.getPicture()))
        return false;
    if(price!=p.price)
        return false;
    if(capacity!=p.capacity)
        return false;
    if(used!=used)
        return false;
    if(alarm!=p.getAlarm())
       return false;
    if(stock!=p.getStock())
        return false;
    return true;
}

Product& Product::operator=(const Product& src)
{
    if(this == &src)
        return *this;
    id=src.getId();
    isDelete=src.getIsDelete();
    name=src.getName();
    picture=src.getPicture();
    price=src.price;
    capacity=src.capacity;
    used=src.used;
    alarm=src.getAlarm();
    stock=src.getStock();
    ingredients=src.getIngredients();
    return *this;
}

bool Product::operator<(const Product &p) const
{
    return id < p.id;
}

//From Serializable interface
QVariant Product::toVariant() const
{
    QVariantMap m;
    QVariantList list;

    m.insert("id",getId());
    m.insert("isDelete",getIsDelete());
    m.insert("stock",getStock());
    m.insert("alarm",getAlarm());
    m.insert("name",getName());
    m.insert("picture",getPicture());

    m.insert("price",price.toVariant());
    m.insert("capacity",capacity.toVariant());
    m.insert("used",used.toVariant());

    for(auto const& i:ingredients)
        list.push_back(i.toVariant());
    m.insert("ingredients",list);
    return m;
}

void Product::fromVariant(const QVariant& variant)
{
    QVariantMap m=variant.toMap();
    QVariantList list=m.value("ingredients").toList();
    std::vector<Ingredient> ingredients;
    setId(m.value("id").toInt());
    setIsDelete(m.value("isDelete").toBool());
    setStock(m.value("stock").toInt());
    setAlarm(m.value("alarm").toInt());
    setName(m.value("name").toString());
    setPicture(m.value("picture").toString());

    price.fromVariant(m.value("price"));
    capacity.fromVariant(m.value("capacity"));
    used.fromVariant(m.value("used"));

    for(auto const& i:list)
    {
        Ingredient c;
        c.fromVariant(i);
        ingredients.push_back(c);
    }
    setIngredients(ingredients);

}


int Product::getId() const
{
    return id;
}

void Product::setId(int value)
{
    id = value;
}

bool Product::getIsDelete() const
{
    return isDelete;
}

void Product::setIsDelete(bool value)
{
    isDelete = value;
}

QString Product::getName() const
{
    return name;
}

void Product::setName(const QString &value)
{
    name = value;
}

QString Product::getPicture() const
{
    return picture;
}

void Product::setPicture(const QString &value)
{
    picture = value;
}

Price Product::getPrice() const
{
    return price;
}

void Product::setPrice(float value)
{
    price.setValue(value);
}

int Product::getStock() const
{
    return stock;
}

void Product::setStock(int value)
{
    stock = value;
}

Capacity Product::getCapacity() const
{
    return capacity;
}

void Product::setCapacity(const float &value)
{
    capacity = value;
}

Capacity Product::getUsed() const
{
    return used;
}

void Product::setUsed(const Capacity &value)
{
    used = value;
}

int Product::getAlarm() const
{
    return alarm;
}

void Product::setAlarm(int value)
{
    alarm = value;
}

std::vector<Ingredient> Product::getIngredients() const
{
    return ingredients;
}

void Product::setIngredients(const std::vector<Ingredient> &value)
{
    ingredients = value;
}
