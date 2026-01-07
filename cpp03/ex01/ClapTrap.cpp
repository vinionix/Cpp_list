#include "ClapTrap.hpp" 

ClapTrap::ClapTrap(const std::string& name) : _name(name), _attackDamage(0), _hitPoints(10), _energyPoints(10) { std::cout << "Constructor called" << std::endl; } 

ClapTrap::ClapTrap(const ClapTrap& copy) : _name(copy._name), _attackDamage(copy._attackDamage), _hitPoints(copy._hitPoints), _energyPoints(copy._energyPoints) { std::cout << "Copy constructor called" << std::endl; }

ClapTrap& ClapTrap::operator=(const ClapTrap& other){ 
	if (this != &other) { 
		this->_name = other._name; 
		this->_hitPoints = other._hitPoints;	
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage; 
	} 
	std::cout << "Copy assignment operator called" << std::endl; return (*this);
} 

ClapTrap::~ClapTrap( void ) { std::cout << "Destructor called" << std::endl; } 

void ClapTrap::attack(const std::string& target) {
	if (this->_energyPoints <= 0 || this->_hitPoints <= 0) { 
		std::cout << "ClapTrap " << this->_name << " can't act" << std::endl; 
		return ; 
	} 
	if (this->_hitPoints > 0 && this->_energyPoints > 0) {
		std::cout << "ClapTrap " << this->_name << " attacks " << target << " causing " << this->_attackDamage << " points of damage!" << std::endl; 
		this->_energyPoints--;
	} 
} 

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hitPoints > 0) {
		std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage!" << std::endl;
		if (amount > (unsigned int)this->_hitPoints) 
			this->_hitPoints = 0; 
		else
			this->_hitPoints -= amount;
	}
} 

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->_energyPoints <= 0 || this->_hitPoints <= 0) {
		std::cout << "ClapTrap " << this->_name << " can't act" << std::endl;
		return ; 
	}
	if (this->_energyPoints > 0 && this->_hitPoints > 0) {
		std::cout << "ClapTrap " << this->_name << " repaired " << amount << " points of life!" << std::endl;
		this->_energyPoints--;
		this->_hitPoints += amount;
	}
} 

std::string ClapTrap::getName( void ) const { return (this->_name); } 

void ClapTrap::setName( const std::string& name ) { this->_name = name; }