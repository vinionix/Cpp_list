#include "ScavTrap.hpp"

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
	
	std::cout << std::endl;

	ScavTrap joão("João");
	
	joão.attack("Roger");
	joão.takeDamage(9);
	joão.beRepaired(1);
	joão.takeDamage(10);
	joão.attack("Roger");
	
	std::cout << std::endl;

	ScavTrap ian(joão);
	
	ian.setName("Ian");
	ian.attack("Roger");
	ian.takeDamage(9);
	ian.beRepaired(1);
	ian.takeDamage(10);
	ian.attack("Roger");

	std::cout << std::endl;

	ScavTrap non = ian;
	
	non.setName("Non");
	non.attack("Roger");
	non.takeDamage(9);
	non.beRepaired(1);
	non.takeDamage(10);
	non.attack("Roger");
	
	std::cout << std::endl;

	joão.guardGate();
	ian.guardGate();
	non.guardGate();

	std::cout << std::endl;

}