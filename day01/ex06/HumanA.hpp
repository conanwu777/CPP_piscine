#ifndef HUMANA_HPP
#define HUMANA_HPP
#include "Weapon.hpp"
#include <iostream>

class HumanA {
	Weapon			&_weapon;
	std::string		_name;
public:
	HumanA(std::string n, Weapon &w);
	~HumanA(void);
	void attack();
};

#endif