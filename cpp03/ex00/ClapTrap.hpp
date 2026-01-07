#pragma once
# include <iostream>

class ClapTrap
{
	private:
		std::string _name;
		int	_attackDamage; 
		int	_hitPoints; 
		int	_energyPoints;
	public:
		ClapTrap(const std::string& name);
		ClapTrap(const ClapTrap& copy);
		ClapTrap& operator=(const ClapTrap& other);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		std::string getName( void ) const;
		void setName( const std::string& name );
		~ClapTrap();
};
