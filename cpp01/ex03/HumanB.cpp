#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name)
{
	gun = NULL;
}

HumanB::~HumanB()
{}

void		HumanB::attack()
{
	if (gun)
		std::cout << name << " attacks with their " << gun->getType() << std::endl;
}
void	HumanB::setWeapon(Weapon& gun)
{
	HumanB::gun = &gun;
}
