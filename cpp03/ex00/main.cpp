#include "ClapTrap.hpp"

int main()
{
	ClapTrap jon("Jon");

	jon.attack("Roger");
	jon.takeDamage(9);
	jon.beRepaired(1);
	jon.takeDamage(10);
	jon.attack("Roger");
	ClapTrap ali(jon);
	ClapTrap ion = ali;

}