#include "Cat.hpp"

Cat::Cat() : Animal(){
	this->type = "Cat";
	std::cout << "Cat builder" << std::endl;
}

Cat& Cat::operator=(const Cat& other){
	if (this != &other){
		this->type = other.type;
	}
	return *this;
}

Cat::Cat(const Cat& copy) : Animal(copy){ std::cout << "Cat copy builder" << std::endl; }

void Cat::makeSound() const{
	std::cout << "Meow" << std::endl;
}

Cat::~Cat(){ std::cout << "Cat destroyer" << std::endl; }