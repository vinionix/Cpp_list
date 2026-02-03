#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << std::endl << "Animal:" << std::endl << std::endl;
	
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	delete(meta);
	delete(j);
	delete(i);

	std::cout << std::endl << "WrongAnimal:" << std::endl << std::endl;

	const WrongAnimal* wrongAnimal = new WrongAnimal();
	const WrongAnimal* cat = new WrongCat();
	std::cout << wrongAnimal->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	cat->makeSound();
	wrongAnimal->makeSound();
	delete(wrongAnimal);
	delete(cat);
	return 0;
}