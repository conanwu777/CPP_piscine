#ifndef HUMANB_HPP
#define HUMANB_HPP
#include "Weapon.hpp"
#include <iostream>

class HumanB {
	Weapon			*_weapon;
	std::string		_name;
public:
	HumanB(const std::string n);
	~HumanB(void);
	void attack();
	void setWeapon(Weapon &w);
};

#endif