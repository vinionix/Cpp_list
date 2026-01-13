#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	std::cout << std::endl;
	std::cout << "/****************************ClapTrap***************************/" << std::endl;
	std::cout << std::endl;

	ClapTrap jon("Jon");
	
	jon.attack("Roger");
	jon.takeDamage(9);
	jon.beRepaired(1);
	jon.takeDamage(10);
	jon.attack("Roger");
	
	ClapTrap ali(jon);
	ClapTrap ion = ali;
	
	std::cout << std::endl;
	std::cout << "/***************************************************************/" << std::endl;
	std::cout << std::endl;
	std::cout << "/****************************ScavTrap***************************/" << std::endl;
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

	std::cout << std::endl;
	std::cout << "/***************************************************************/" << std::endl;
	std::cout << std::endl;
	std::cout << "/****************************FragTrap***************************/" << std::endl;
	std::cout << std::endl;

	FragTrap alan("Alan");
	
	alan.attack("Mario");
	alan.takeDamage(9);
	alan.beRepaired(1);
	alan.takeDamage(10);
	alan.attack("Mario");
	
	std::cout << std::endl;

	FragTrap jo(alan);
	
	jo.setName("Jo");
	jo.attack("Mario");
	jo.takeDamage(9);
	jo.beRepaired(1);
	jo.takeDamage(10);
	jo.attack("Mario");

	std::cout << std::endl;

	FragTrap flavio = jo;

	flavio.setName("Flavio");
	flavio.attack("Mario");
	flavio.takeDamage(9);
	flavio.beRepaired(1);
	flavio.takeDamage(10);
	flavio.attack("Mario");
	
	std::cout << std::endl;

 	alan.highFivesGuys();
	jo.highFivesGuys();
	flavio.highFivesGuys();

}