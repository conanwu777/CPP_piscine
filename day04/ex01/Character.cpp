#include "Character.hpp"
#include "AWeapon.hpp"
#include "Enemy.hpp"
#include <iostream>

Character::Character(){}

Character::Character(std::string const & name)
: name(name), ap(40), weapon(NULL){}

Character::Character(Character const & src) {
	*this = src;}

Character::~Character(){}

Character & Character::operator=(Character const & rhs) {
	this->name = rhs.getName();
	this->ap = rhs.ap;
	this->weapon = rhs.weapon;
	return (*this);
}

void Character::recoverAP() {
	this->ap += 10;
	if (this->ap > 40)
		this->ap = 40;
}

void Character::equip(AWeapon* w) {
	this->weapon = w;
}

void Character::attack(Enemy* e) {
	if (!this->weapon || this->ap < this->weapon->getAPCost())
		return ;
	this->ap -= this->weapon->getAPCost();
	std::cout << this->name << " attacks " << e->getType() <<
	" with a " << this->weapon->getName() << std::endl;
	this->weapon->attack();
	e->takeDamage(this->weapon->getDamage());
	if (e->getHP() == 0)
		delete e;
}

std::string const Character::getName() const {
	return (this->name);
}

std::ostream & operator<<(std::ostream & ofs, const Character & s) {
	if (s.weapon)
		ofs << s.getName() << " has " << s.ap << " AP and wields a "
		<< s.weapon->getName() << std::endl;
	else
		ofs << s.getName() << " has " << s.ap << " AP and is unarmed\n";
	return (ofs);
}
