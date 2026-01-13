#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& name) :  ClapTrap(name) { 
	this->_attackDamage = 30;
	this->_energyPoints = 100;
	this->_hitPoints = 100;
	std::cout << "FragTrap Constructor called" << std::endl; 
} 

FragTrap::FragTrap(const FragTrap& copy) : ClapTrap(copy) { std::cout << "FragTrap copy constructor called" << std::endl; }

FragTrap& FragTrap::operator=(const FragTrap& other){ 
	if (this != &other) { 
		this->_name = other._name; 
		this->_hitPoints = other._hitPoints;	
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage; 
	} 
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	return (*this);
} 

FragTrap::~FragTrap( void ) { std::cout << "FragTrap destructor called" << std::endl; } 

void FragTrap::attack(const std::string& target) {
	if (this->_energyPoints <= 0 || this->_hitPoints <= 0) { 
		std::cout << "FragTrap " << this->_name << " can't act" << std::endl; 
		return ; 
	} 
	if (this->_hitPoints > 0 && this->_energyPoints > 0) {
		std::cout << "FragTrap " << this->_name << " attacks " << target << " causing " << this->_attackDamage << " points of damage!" << std::endl; 
		this->_energyPoints--;
	} 
} 

void FragTrap::takeDamage(unsigned int amount) {
	if (this->_hitPoints > 0) {
		std::cout << "FragTrap " << this->_name << " takes " << amount << " points of damage!" << std::endl;
		if (amount > (unsigned int)this->_hitPoints) 
			this->_hitPoints = 0; 
		else
			this->_hitPoints -= amount;
	}
} 

void FragTrap::beRepaired(unsigned int amount) {
	if (this->_energyPoints <= 0 || this->_hitPoints <= 0) {
		std::cout << "FragTrap " << this->_name << " can't act" << std::endl;
		return ; 
	}
	if (this->_energyPoints > 0 && this->_hitPoints > 0) {
		std::cout << "FragTrap " << this->_name << " repaired " << amount << " points of life!" << std::endl;
		this->_energyPoints--;
		this->_hitPoints += amount;
	}
} 

void FragTrap::highFivesGuys() {
	std::cout << "FragTrap " << "High Five Guys" << std::endl;
}
