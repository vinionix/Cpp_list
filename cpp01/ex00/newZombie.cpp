#include "Zombie.hpp"

Zombie*	newZombie( std::string name )
{
	Zombie	*new_Zombie = new Zombie;

	new_Zombie->get_name() = name;
	return(new_Zombie);
}
