#ifndef FRAGTRAP_H
# define FRAGTRAP_H
# include <iostream>
# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
public:
	FragTrap(void);
	FragTrap(FragTrap const &src);
	FragTrap(std::string const name);
	~FragTrap(void);

	void rangedAttack(std::string const & target);
	void meleeAttack(std::string const & target);
	void vaulthunter_dot_exe(std::string const & target);
};

#endif
