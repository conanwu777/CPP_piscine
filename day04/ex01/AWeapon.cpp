#include "AWeapon.hpp"
#include <iostream>

AWeapon::AWeapon(std::string const & name, int apcost, int damage) :
name(name), apcost(apcost), damage(damage){}

AWeapon::AWeapon(){}

AWeapon::AWeapon(AWeapon const & src){
	*this = src;}

AWeapon::~AWeapon(){}

AWeapon & AWeapon::operator=(AWeapon const & rhs) {
	this->name = rhs.getName();
	this->apcost = rhs.getAPCost();
	this->damage = rhs.getDamage();
	return (*this);}

std::string const AWeapon::getName() const {
	return (this->name);}

int AWeapon::getAPCost() const {
	return (this->apcost);
}
int AWeapon::getDamage() const {
	return (this->damage);
}
