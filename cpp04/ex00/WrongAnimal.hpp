#pragma once
# include <iostream>

class WrongAnimal {
	protected:
		std::string	type;
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& copy);
		WrongAnimal& operator=(const WrongAnimal& other);
		void makeSound() const;
		std::string getType() const;
		~WrongAnimal();
};