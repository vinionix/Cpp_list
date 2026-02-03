#pragma once
# include "Animal.hpp"

class Cat : public Animal{
	public:
		Cat();
		void makeSound() const;
		Cat(const Cat& copy);
		Cat& operator=(const Cat &other);
		~Cat();
};