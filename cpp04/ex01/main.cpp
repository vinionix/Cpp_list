#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
{
	Animal* animal[100];
	for (int i = 0; i < 100; i++) {
		if (i % 2 == 0)
			animal[i] = new Cat();
		else{
			animal[i] = new Dog();
		}
		animal[i]->makeSound();
	}
	for (int i = 0; i < 100; i++) {
		std::cout << i << std::endl;
		if (animal[i])
			delete(animal[i]);
	}
}