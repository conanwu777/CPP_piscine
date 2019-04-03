#ifndef NINJATRAP_H
# define NINJATRAP_H
# include <iostream>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "ClapTrap.hpp"

class NinjaTrap : virtual public ClapTrap {
public:
	NinjaTrap(void);
	NinjaTrap(NinjaTrap const &src);
	NinjaTrap(std::string const name);
	~NinjaTrap(void);

	void rangedAttack(std::string const & target);
	void meleeAttack(std::string const & target);
	void ninjaShoebox(ClapTrap &t);
	void ninjaShoebox(ScavTrap &t);
	void ninjaShoebox(FragTrap &t);
	void ninjaShoebox(NinjaTrap &t);
};

#endif
