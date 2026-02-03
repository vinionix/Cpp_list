#include "Animal.hpp"

Animal::Animal() : type("Animal"){ std::cout << "Animal builder" << std::endl; }

Animal& Animal::operator=(const Animal& other){
	if (this != &other){
		this->type = other.type;
	}
	return *this;
}

Animal::Animal(const Animal& copy) : type(copy.type){ std::cout << "Animal copy builder" << std::endl; }

std::string Animal::getType() const{
	return type;
}

void Animal::makeSound() const{
	std::cout << "I'm an Animal, I have no sound, because I don't know what kind of Animal I'am" << std::endl;
}

Animal::~Animal(){ std::cout << "Animal destroyer" << std::endl; }