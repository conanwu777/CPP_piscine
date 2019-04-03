#include "FragTrap.hpp"

FragTrap::FragTrap() {
	this->hp = 100;
	this->mhp = 100;
	this->ep = 100;
	this->mep = 100;
	this->lvl = 1;
	this->name = "FragTrap";
	this->MeleeDam = 30;
	this->RangedDam = 20;
	this->ArmorDam = 5;
	srand(time(NULL));
	std::cout << this->name << ": Hello! I am your new steward bot.\n";
}

FragTrap::FragTrap(FragTrap const &src) {
	srand(time(NULL));
	*this = src;
	std::cout << this->name << ": Hey everybody! Check out my package!\n";
}

FragTrap::FragTrap(std::string const name) {
	this->hp = 100;
	this->mhp = 100;
	this->ep = 100;
	this->mep = 100;
	this->lvl = 1;
	this->name = name;
	this->MeleeDam = 30;
	this->RangedDam = 20;
	this->ArmorDam = 5;
	srand(time(NULL));
	std::cout << this->name << ": Let's get this party started!\n";
}

FragTrap::~FragTrap() {
	std::cout << this->name << ": Are you god? Am I dead? *NOISE AND BLACKEDOUT*\n";
}

void FragTrap::rangedAttack(std::string const & target) {
	std::cout << this->name << ": Take two bullets, call me in the morning. <"
	<< this->name << "> attacks <" << target
	<< "> at range, causing " << this->RangedDam << " points of damage !\n";
}

void FragTrap::meleeAttack(std::string const & target) {
	std::cout << this->name << ": Ready for the PUNCHline?! <"
	<< this->name << "> attacks <" << target
	<< "> up close, causing " << this->MeleeDam << " points of damage !\n";
}

void FragTrap::vaulthunter_dot_exe(std::string const & target) {
	int r;

	r = rand() % 5;
	if (this->ep < 25)
	{
		std::cout << this->name << ": Too tired...=.= can't move...\n";
		return ;
	}
	this->ep -= 25;
	if (r == 0)
		std::cout << this->name << ": I brought you a present: EXPLOSIONS! <" << this->name
	<< "> launched a Torgue Fiesta at <" << target << ">\n";
	else if (r == 1)
		std::cout << this->name << ": Flesh fireworks! <" << this->name
	<< "> launched a Load 'n' splode at <" << target << ">\n";
	else if (r == 2)
		std::cout << this->name << ": Freeze! I don't know why I said that. <" << this->name
	<< "> launched a cyro attack at <" << target << ">\n";
	else if (r == 3)
		std::cout << this->name << ": Eat bomb, baddie! <" << this->name
	<< "> threw a grenade at <" << target << ">\n";
	else
		std::cout << this->name << ": Psychedelic, man! <" << this->name
	<< "> shoot a laser beam at <" << target << ">\n";
}
