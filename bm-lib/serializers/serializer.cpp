#include "serializer.h"


Serializer::Serializer()
{
}

Serializer::~Serializer()
{

}

int Serializer::getLastId() const
{
    return lastId;
}

void Serializer::setLastId(int value)
{
    lastId = value;
}
