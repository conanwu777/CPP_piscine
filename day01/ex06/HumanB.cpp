#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(const std::string n) : _weapon(NULL), _name(n) {}

HumanB::~HumanB(void){}

void HumanB::attack() {
	std::cout << this->_name << " attacks with his "
	<< this->_weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &w) {
	this->_weapon = &w;
}