#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string n, Weapon &w) : _weapon(w), _name(n) {}

HumanA::~HumanA(void){}

void HumanA::attack() {
	std::cout << this->_name << " attacks with his " << this->_weapon.getType() << std::endl;
}
