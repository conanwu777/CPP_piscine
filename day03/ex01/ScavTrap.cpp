#include "ScavTrap.hpp"
#include <time.h>

ScavTrap::ScavTrap() : hp(100), mhp(100), ep(50), mep(50), lvl(1), name("ScavTrap"),
	MeleeDam(20), RangedDam(15), ArmorDam(3){
	srand(time(NULL));
	std::cout << this->name << ": Hello! I will guard your doors.\n";
}

ScavTrap::ScavTrap(ScavTrap const &src) {
	srand(time(NULL));
	*this = src;
	std::cout << this->name << ": I am reborn!\n";
}

ScavTrap::ScavTrap(std::string const name) : hp(100), mhp(100), ep(50), mep(50), lvl(1),
	name(name), MeleeDam(20), RangedDam(15), ArmorDam(3){
	srand(time(NULL));
	std::cout << this->name << ": None shall pass me!\n";
}

ScavTrap::~ScavTrap() {
	std::cout << this->name << ": Argh arghargh death gurgle gurglegurgle urgh... death.\n";
}

ScavTrap & ScavTrap::operator=(ScavTrap const & rhs) {
	std::string old;

	old = this->name;
	if (this != &rhs) {
		this->hp = rhs.hp;
		this->mhp = rhs.mhp;
		this->ep = rhs.ep;
		this->lvl = rhs.lvl;
		this->name = rhs.name;
		this->MeleeDam = rhs.MeleeDam;
		this->RangedDam = rhs.RangedDam;
		this->ArmorDam = rhs.ArmorDam;
	}
	std::cout << "An identical copy of " << this->name << " has replaced " << old << std::endl;
	return (*this);
}

void ScavTrap::takeDamage(unsigned int amount) {
	if ((unsigned int)this->ArmorDam <= amount)
		amount -= (unsigned int)this->ArmorDam;
	else
		amount = 0;
	if ((unsigned int)this->hp >= amount)
		this->hp -= amount;
	else
		this->hp = 0;
	std::cout << this->name << ": I'm too pretty to die! <" << this->name
	<< "> took a damage, current hp is " << this->hp << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount) {
	if ((unsigned int)this->hp + amount <= (unsigned int)this->mhp)
		this->hp += amount;
	else
		this->hp = this->mhp;
	std::cout << this->name << ": Sweet life juice! <" << this->name
	<< "> got a repair, current hp is " << this->hp << std::endl;
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
