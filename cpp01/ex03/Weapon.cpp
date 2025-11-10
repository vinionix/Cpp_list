#include "Weapon.hpp"

std::string&	Weapon::getType()
{
	return (type);
}

void	Weapon::setType(std::string name)
{
	type = name;
}

Weapon::Weapon(std::string type) : type(type)
{}

Weapon::~Weapon()
{}
