#ifndef SUPERTRAP_H
# define SUPERTRAP_H
# include <iostream>
#include "FragTrap.hpp"
#include "NinjaTrap.hpp"

class SuperTrap : public NinjaTrap, public FragTrap {
public:
	SuperTrap(void);
	SuperTrap(SuperTrap const &src);
	SuperTrap(std::string const name);
	~SuperTrap(void);

	void rangedAttack(std::string const & target);
	void meleeAttack(std::string const & target);
};

#endif
