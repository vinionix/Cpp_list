#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& name) :  ClapTrap(name) { 
	this->_attackDamage = 20;
	this->_energyPoints = 50;
	this->_hitPoints = 100;
	std::cout << "ScavTrap Constructor called" << std::endl; 
} 

ScavTrap::ScavTrap(const ScavTrap& copy) : ClapTrap(copy) { std::cout << "ScavTrap copy constructor called" << std::endl; }

ScavTrap& ScavTrap::operator=(const ScavTrap& other){ 
	if (this != &other) { 
		this->_name = other._name; 
		this->_hitPoints = other._hitPoints;	
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage; 
	} 
	std::cout << "ScavTrap copy assignment operator called" << std::endl; return (*this);
} 

ScavTrap::~ScavTrap( void ) { std::cout << "ScavTrap destructor called" << std::endl; } 

void ScavTrap::attack(const std::string& target) {
	if (this->_energyPoints <= 0 || this->_hitPoints <= 0) { 
		std::cout << "ScavTrap " << this->_name << " can't act" << std::endl; 
		return ; 
	} 
	if (this->_hitPoints > 0 && this->_energyPoints > 0) {
		std::cout << "ScavTrap " << this->_name << " attacks " << target << " causing " << this->_attackDamage << " points of damage!" << std::endl; 
		this->_energyPoints--;
	} 
} 

void ScavTrap::takeDamage(unsigned int amount) {
	if (this->_hitPoints > 0) {
		std::cout << "ScavTrap " << this->_name << " takes " << amount << " points of damage!" << std::endl;
		if (amount > (unsigned int)this->_hitPoints) 
			this->_hitPoints = 0; 
		else
			this->_hitPoints -= amount;
	}
} 

void ScavTrap::beRepaired(unsigned int amount) {
	if (this->_energyPoints <= 0 || this->_hitPoints <= 0) {
		std::cout << "ScavTrap " << this->_name << " can't act" << std::endl;
		return ; 
	}
	if (this->_energyPoints > 0 && this->_hitPoints > 0) {
		std::cout << "ScavTrap " << this->_name << " repaired " << amount << " points of life!" << std::endl;
		this->_energyPoints--;
		this->_hitPoints += amount;
	}
} 

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << this->_name << " is now in gatekeeper mode." << std::endl;
}
