#include "Serializer.hpp"
#include "iostream"

int main(){
    Data num;

    num.number = 10;
    std::cout << "num->number original: " << num.number << std::endl;
    uintptr_t uInt = Serializer::serialize(&num);
    num = *Serializer::deserialize(uInt);
    std::cout << "num->number alterado: " << num.number << std::endl; 
}