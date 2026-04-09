#include "AAnimal.hpp"

AAnimal::AAnimal() : type("AAnimal"){ std::cout << "AAnimal builder" << std::endl; }

AAnimal& AAnimal::operator=(const AAnimal& other){
	if (this != &other){
		this->type = other.type;
	}
	return *this;
}

AAnimal::AAnimal(const AAnimal& copy) : type(copy.type){ std::cout << "AAnimal copy builder" << std::endl; }

std::string AAnimal::getType() const{
	return type;
}

AAnimal::~AAnimal(){ std::cout << "AAnimal destroyer" << std::endl; }