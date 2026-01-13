#pragma once
# include <iostream>

class ClapTrap
{
	protected:
		std::string _name;
		int	_attackDamage; 
		int	_hitPoints; 
		int	_energyPoints;
	public:
		ClapTrap(const std::string& name);
		ClapTrap(const ClapTrap& copy);
		ClapTrap& operator=(const ClapTrap& other);
		virtual void attack(const std::string& target);
		virtual void takeDamage(unsigned int amount);
		virtual void beRepaired(unsigned int amount);
		std::string getName( void ) const;
		void setName( const std::string& name );
		virtual ~ClapTrap();
};
