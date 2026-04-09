#include "Dog.hpp"
#include "Cat.hpp"
#include "AAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
{
	AAnimal* cat = new Cat();
	AAnimal* dog = new Dog();
	cat->getType();
	dog->getType();
	delete(cat);
	delete(dog);

}