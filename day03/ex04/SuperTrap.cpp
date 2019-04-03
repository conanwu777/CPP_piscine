#include "SuperTrap.hpp"
#include "NinjaTrap.hpp"
#include "FragTrap.hpp"

SuperTrap::SuperTrap() {
	this->hp = 100;
	this->mhp = 100;
	this->ep = 120;
	this->mep = 120;
	this->lvl = 1;
	this->name = "SuperTrap";
	this->RangedDam = 20;
	this->MeleeDam = 60;
	this->ArmorDam = 5;
	srand(time(NULL));
	std::cout << "A new SuperTrap is born." << std::endl;
}

SuperTrap::SuperTrap(SuperTrap const &src) {
	srand(time(NULL));
	*this = src;
	std::cout << this->name << "splitted, hence creating a new SuperTrap\n";
}

SuperTrap::SuperTrap(std::string const name) {
	this->hp = 100;
	this->mhp = 100;
	this->ep = 120;
	this->mep = 120;
	this->lvl = 1;
	this->name = name;
	this->RangedDam = 20;
	this->MeleeDam = 60;
	this->ArmorDam = 5;
	srand(time(NULL));
	std::cout << "A new SuperTrap appeared, they call him " << this->name << std::endl;
}

SuperTrap::~SuperTrap() {
	std::cout << this->name << " turned into a permenant disturbance to the universe\n";
}

void SuperTrap::rangedAttack(std::string const & target) {
	FragTrap::rangedAttack(target);
}

void SuperTrap::meleeAttack(std::string const & target) {
	NinjaTrap::meleeAttack(target);
}
