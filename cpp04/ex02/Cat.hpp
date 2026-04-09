#pragma once

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal{
	private:
		Brain *brain;
	public:
		Cat();
		void makeSound() const;
		Cat(const Cat& copy);
		Cat& operator=(const Cat &other);
		~Cat();
};