#include "Zombie.hpp"

Zombie::Zombie( void ){}

Zombie::~Zombie( void ){}

std::string& Zombie::get_name()
{
	return (name);
}

void Zombie::announce( void )
{
    std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}
