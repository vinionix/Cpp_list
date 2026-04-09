#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal"){ std::cout << "WrongAnimal builder" << std::endl; }

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other){
	if (this != &other){
		this->type = other.type;
	}
	return *this;
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy) : type(copy.type){ std::cout << "WrongAnimal copy builder" << std::endl; }

std::string WrongAnimal::getType() const{
	return type;
}

void WrongAnimal::makeSound() const{
	std::cout << "I'm an WrongAnimal, I have no sound, because I don't know what kind of WrongAnimal I'am" << std::endl;
}

WrongAnimal::~WrongAnimal(){ std::cout << "WrongAnimal destroyer" << std::endl; }