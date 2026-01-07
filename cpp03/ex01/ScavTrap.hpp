#pragma once
#include "ClapTrap.hpp"


class ScavTrap : public ClapTrap{
	public:
		ScavTrap(const std::string& name);
		ScavTrap(const ScavTrap& copy);
		ScavTrap& operator=(const ScavTrap& other);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void guardGate( void );
		~ScavTrap();

};