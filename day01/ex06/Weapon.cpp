#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon(const std::string t) {
	this->_type = &t;
}

Weapon::~Weapon(){}

const std::string &Weapon::getType(void) const {
	return (*(this->_type));
}

void Weapon::setType(const std::string str) {
	this->_type = &str;
}
