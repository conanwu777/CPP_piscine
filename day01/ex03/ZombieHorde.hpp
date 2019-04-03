#ifndef ZOMBIE_HORDE_HPP
#define ZOMBIE_HORDE_HPP
#include "Zombie.hpp"
#include <iostream>

class ZombieHorde {
	Zombie *_horde;
	int		_num;
	public:
	ZombieHorde(int N);
	~ZombieHorde(void);
	void announce(void);
};

#endif
