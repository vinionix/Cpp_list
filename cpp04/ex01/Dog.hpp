#pragma once

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal{
	private:
		Brain *brain;
	public:
		Dog();
		void makeSound() const;
		Dog(const Dog& copy);
		Dog& operator=(const Dog &other);
		~Dog();
};