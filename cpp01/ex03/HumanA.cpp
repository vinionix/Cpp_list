#include "HumanA.hpp"

void		HumanA::attack()
{
	std::cout << name << " attacks with their " << gun.getType() << std::endl; 
}

HumanA::HumanA(std::string name, Weapon& gun) : name(name), gun(gun)
{}

HumanA::~HumanA()
{}
