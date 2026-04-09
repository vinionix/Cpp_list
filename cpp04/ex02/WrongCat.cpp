#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal(){
	this->type = "WrongCat";
	std::cout << "WrongCat builder" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other){
	if (this != &other){
		this->type = other.type;
	}
	return *this;
}

WrongCat::WrongCat(const WrongCat& copy) : WrongAnimal(copy){ std::cout << "WrongCat copy builder" << std::endl; }

void WrongCat::makeSound() const{
	std::cout << "Meow" << std::endl;
}

WrongCat::~WrongCat(){ std::cout << "WrongCat destroyer" << std::endl; }