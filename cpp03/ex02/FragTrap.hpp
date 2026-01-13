#pragma once
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap{
    public:
        FragTrap(const std::string& name);
		FragTrap(const FragTrap& copy);
		FragTrap& operator=(const FragTrap& other);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
        void highFivesGuys(void);
        ~FragTrap();
};