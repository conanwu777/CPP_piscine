#include "NinjaTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "ClapTrap.hpp"

NinjaTrap::NinjaTrap() {
	this->hp = 60;
	this->mhp = 60;
	this->ep = 120;
	this->mep = 120;
	this->lvl = 1;
	this->name = "NinjaTrap";
	this->MeleeDam = 60;
	this->RangedDam = 5;
	this->ArmorDam = 0;
	srand(time(NULL));
	std::cout << "A new NinjaTrap appeared" << std::endl;
}

NinjaTrap::NinjaTrap(NinjaTrap const &src) {
	srand(time(NULL));
	*this = src;
	std::cout << this->name << "splitted, hence creating a copy of himself\n";
}

NinjaTrap::NinjaTrap(std::string const name) {
	this->hp = 60;
	this->mhp = 60;
	this->ep = 120;
	this->mep = 120;
	this->lvl = 1;
	this->name = name;
	this->MeleeDam = 60;
	this->RangedDam = 5;
	this->ArmorDam = 0;
	srand(time(NULL));
	std::cout << "A new NinjaTrap appeared, they call him " << this->name << std::endl;
}

NinjaTrap::~NinjaTrap() {
	std::cout << this->name << " turned into purple smoke\n";
}

void NinjaTrap::rangedAttack(std::string const & target) {
	std::cout << this->name << " shoot a shuriken at "
	<< target << " from afar. Causing " << this->RangedDam << " points of damage\n";
}

void NinjaTrap::meleeAttack(std::string const & target) {
	std::cout << this->name << " quietly sneaked up to " << target
	<< " and poked him with a poisoned dagger. Causing " << this->MeleeDam << " points of damage.\n";
}

void NinjaTrap::ninjaShoebox(ClapTrap &t) {
	t.hp += 10;
	std::cout << this->name << " threw out a shoebox, "
	<< "the ClapTrap found a new pair of shoes\n";
}

void NinjaTrap::ninjaShoebox(ScavTrap &t) {
	t.hp = 0;
	std::cout << this->name << " threw out a shoebox, "
	"it killed the poor ScavTrap\n";
}

void NinjaTrap::ninjaShoebox(FragTrap &t) {
	t.hp += 0;
	std::cout << this->name << " threw out a shoebox, "
	"the confused FragTrap walked away unharmed\n";
}

void NinjaTrap::ninjaShoebox(NinjaTrap &t) {
	t.hp += 10;
	std::cout << this->name << " threw out a shoebox, "
	"the NinjaTrap threw it back in a flash\n";
}
