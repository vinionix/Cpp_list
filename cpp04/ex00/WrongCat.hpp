#pragma once
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal{
	public:
		WrongCat();
		void makeSound() const;
		WrongCat(const WrongCat& copy);
		WrongCat& operator=(const WrongCat &other);
		~WrongCat();
};