#pragma once
#include "Weapon.hpp"

class HumanB
{
	private:
		std::string name;
		Weapon*		gun;
	public:
		HumanB(std::string name);
		~HumanB();
		void		attack();
		void		setWeapon(Weapon& gun);
};
