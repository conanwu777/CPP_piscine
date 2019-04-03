#ifndef SCAVTRAP_H
# define SCAVTRAP_H
# include <iostream>
# include "FragTrap.hpp"

class ScavTrap {
public:
	int hp;
	int mhp;
	int ep;
	int mep;
	int lvl;
	std::string name;
	int MeleeDam;
	int RangedDam;
	int ArmorDam;

	ScavTrap(void);
	ScavTrap(ScavTrap const &src);
	ScavTrap(std::string const name);
	~ScavTrap(void);

	ScavTrap & operator=(ScavTrap const & rhs);

	void rangedAttack(std::string const & target);
	void meleeAttack(std::string const & target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void challengeNewcomer(std::string const & target);
};

#endif
