#pragma once
#include "iostream"

class Zombie
{
	private:
		std::string	name;
	public:
		Zombie( void );
		std::string& get_name();
		void announce( void );
		~Zombie( void );
};

Zombie* zombieHorde( int N, std::string name );
