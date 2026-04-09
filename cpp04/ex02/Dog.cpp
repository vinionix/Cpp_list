#include "Dog.hpp"

Dog::Dog() : AAnimal(){
	this->type = "Dog";
	std::cout << "Dog builder" << std::endl;
	this->brain = new Brain();
}

Dog& Dog::operator=(const Dog& other){
	if (this != &other){
		this->type = other.type;
	}
	return *this;
}

Dog::Dog(const Dog& copy) : AAnimal(copy){}

void Dog::makeSound() const{
	std::cout << "Woof" << std::endl;
}

Dog::~Dog(){
	delete(this->brain);
	std::cout << "Dog destroyer" << std::endl;
}