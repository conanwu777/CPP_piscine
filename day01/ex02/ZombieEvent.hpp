#ifndef ZOMBIE_EVENT_HPP
#define ZOMBIE_EVENT_HPP
#include "Zombie.hpp"
#include <iostream>

class ZombieEvent {
public:
	std::string ZombieType;
	ZombieEvent(void);
	~ZombieEvent(void);
	void setZombieType(std::string t);
	Zombie *newZombie(std::string name);
	void randomChump(void);
};

#endif