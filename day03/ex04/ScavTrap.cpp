#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
	this->hp = 100;
	this->mhp = 100;
	this->ep = 50;
	this->mep = 50;
	this->lvl = 1;
	this->name = "ScavTrap";
	this->MeleeDam = 20;
	this->RangedDam = 15;
	this->ArmorDam = 3;
	srand(time(NULL));
	std::cout << this->name << ": Hello! I will guard your doors.\n";
}

ScavTrap::ScavTrap(ScavTrap const &src) {
	srand(time(NULL));
	*this = src;
	std::cout << this->name << ": I am reborn!\n";
}

ScavTrap::ScavTrap(std::string const name) {
	this->hp = 100;
	this->mhp = 100;
	this->ep = 50;
	this->mep = 50;
	this->lvl = 1;
	this->name = name;
	this->MeleeDam = 20;
	this->RangedDam = 15;
	this->ArmorDam = 3;
	srand(time(NULL));
	std::cout << this->name << ": None shall pass me!\n";
}

ScavTrap::~ScavTrap() {
	std::cout << this->name << ": Argh arghargh death gurgle gurglegurgle urgh... death.\n";
}

void ScavTrap::rangedAttack(std::string const & target) {
	std::cout << this->name << ": die spy die!!! <"
	<< this->name << "> attacks <" << target
	<< "> at range, causing " << this->RangedDam << " points of damage !\n";
}

void ScavTrap::meleeAttack(std::string const & target) {
	std::cout << this->name << ": Get out! <"
	<< this->name << "> attacks <" << target
	<< "> up close, causing " << this->MeleeDam << " points of damage !\n";
}

void ScavTrap::challengeNewcomer(std::string const & target) {
	int r;

	r = rand() % 5;
	if (r == 0)
		std::cout << this->name << ": I'm thirsty... <" << this->name
	<< "> made <" << target << "> get coffee at Starbucks\n";
	else if (r == 1)
		std::cout << this->name << ": I bet you can't push up <" << this->name
	<< "> made <" << target << "> do 42 push-ups\n";
	else if (r == 2)
		std::cout << this->name << ": Show me what you've got! <" << this->name
	<< "> made <" << target << "> dress in Bikini and pole-dance\n";
	else if (r == 3)
		std::cout << this->name << ": Can you code?<" << this->name
	<< "> made <" << target << "> do a day's homework for him\n";
	else
		std::cout << this->name << ": I want unicorns! <" << this->name
	<< "> made <" << target << "> wear a unicorn suit\n";
}
