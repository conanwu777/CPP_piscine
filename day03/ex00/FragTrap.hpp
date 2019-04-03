#ifndef FRAGTRAP_H
# define FRAGTRAP_H
# include <iostream>

class FragTrap {
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

	FragTrap(void);
	FragTrap(FragTrap const &src);
	FragTrap(std::string const name);
	~FragTrap(void);

	FragTrap & operator=(FragTrap const & rhs);

	void rangedAttack(std::string const & target);
	void meleeAttack(std::string const & target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void vaulthunter_dot_exe(std::string const & target);
};

#endif
