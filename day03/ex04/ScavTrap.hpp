#ifndef SCAVTRAP_H
# define SCAVTRAP_H
# include <iostream>
# include "FragTrap.hpp"

class ScavTrap : public ClapTrap {
public:
	ScavTrap(void);
	ScavTrap(ScavTrap const &src);
	ScavTrap(std::string const name);
	~ScavTrap(void);

	void rangedAttack(std::string const & target);
	void meleeAttack(std::string const & target);
	void challengeNewcomer(std::string const & target);
};

#endif
