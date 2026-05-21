#include "Serializer.hpp"

Serializer::Serializer(){}

Serializer::~Serializer(){}

uintptr_t Serializer::serialize(Data* ptr){
    uintptr_t temp = static_cast<uintptr_t>(ptr->number);
    return (temp);
}

Data* Serializer::deserialize(uintptr_t raw){
    Data *temp = new Data;

    temp->number = static_cast<int>(raw);
    return(temp);
}
