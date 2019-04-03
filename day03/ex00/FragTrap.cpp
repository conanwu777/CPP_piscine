#include "FragTrap.hpp"
#include <time.h>

FragTrap::FragTrap() : hp(100), mhp(100), ep(100), mep(100), lvl(1), name("FragTrap"),
	MeleeDam(30), RangedDam(20), ArmorDam(5){
	srand(time(NULL));
	std::cout << this->name << ": Hello! I am your new steward bot.\n";
}

FragTrap::FragTrap(FragTrap const &src) {
	srand(time(NULL));
	*this = src;
	std::cout << this->name << ": Hey everybody! Check out my package!\n";
}

FragTrap::FragTrap(std::string const name) : hp(100), mhp(100), ep(100), mep(100),
	lvl(1), name(name), MeleeDam(30), RangedDam(20), ArmorDam(5){
	srand(time(NULL));
	std::cout << this->name << ": Let's get this party started!\n";
}

FragTrap::~FragTrap() {
	std::cout << this->name << ": Are you god? Am I dead? *NOISE AND BLACKEDOUT*\n";
}

FragTrap & FragTrap::operator=(FragTrap const & rhs) {
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

void FragTrap::takeDamage(unsigned int amount) {
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

void FragTrap::beRepaired(unsigned int amount) {
	if ((unsigned int)this->hp + amount <= (unsigned int)this->mhp)
		this->hp += amount;
	else
		this->hp = this->mhp;
	std::cout << this->name << ": Sweet life juice! <" << this->name
	<< "> got a repair, current hp is " << this->hp << std::endl;
}

void FragTrap::vaulthunter_dot_exe(std::string const & target) {
	int r;

	r = rand() % 5;
	if (this->ep < 25)
		r = -1;
	else
		this->ep -= 25;
	switch (r)
	{
		case 0:
			std::cout << this->name << ": I brought you a present: EXPLOSIONS! <" << this->name
		<< "> launched a Torgue Fiesta at <" << target << ">\n";
			break ;
		case 1:
			std::cout << this->name << ": Flesh fireworks! <" << this->name
		<< "> launched a Load 'n' splode at <" << target << ">\n";
			break ;
		case 2:
			std::cout << this->name << ": Freeze! I don't know why I said that. <" << this->name
		<< "> launched a cyro attack at <" << target << ">\n";
			break ;
		case 3:
			std::cout << this->name << ": Eat bomb, baddie! <" << this->name
		<< "> threw a grenade at <" << target << ">\n";
			break ;
		case 4:
			std::cout << this->name << ": Psychedelic, man! <" << this->name
		<< "> shoot a laser beam at <" << target << ">\n";
			break ;
		default:
			std::cout << this->name << ": Too tired...=.= can't move...\n";
	}
}
