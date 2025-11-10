#pragma once
#include "iostream"

class Zombie
{
	private:
		std::string	name;
	public:
		std::string& get_name();
		void announce( void );
};

Zombie* zombieHorde( int N, std::string name );
