#include "Dog.hpp"

Dog::Dog() : Animal(){
	this->type = "Dog";
	std::cout << "Dog builder" << std::endl;
}

Dog& Dog::operator=(const Dog& other){
	if (this != &other){
		this->type = other.type;
	}
	return *this;
}

Dog::Dog(const Dog& copy) : Animal(copy){ std::cout << "Dog copy builder" << std::endl; }

void Dog::makeSound() const{
	std::cout << "Woof" << std::endl;
}

Dog::~Dog(){ std::cout << "Dog destroyer" << std::endl; }