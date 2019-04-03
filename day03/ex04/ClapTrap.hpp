#ifndef CLAPTRAP_H
# define CLAPTRAP_H
# include <iostream>

class ClapTrap {
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

	ClapTrap(void);
	ClapTrap(ClapTrap const &src);
	ClapTrap(std::string const name);
	~ClapTrap(void);

	ClapTrap & operator=(ClapTrap const & rhs);

	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif