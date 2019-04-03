#include "Zombie.hpp"
#include "ZombieEvent.hpp"
#include <iostream>

ZombieEvent::ZombieEvent(void) {}

ZombieEvent::~ZombieEvent(void){}

void ZombieEvent::setZombieType(std::string t) {
	this->ZombieType = t;
}

Zombie *ZombieEvent::newZombie(std::string n) {
	Zombie *z = new Zombie(n, this->ZombieType);
	return (z);
}

void ZombieEvent::randomChump(void) {
	int i = -1;
	std::string nrand;
	std::string al = "@#$&*().!>";
	Zombie *z;

	srand(time(NULL));
	while (++i < 7)
		nrand += al[rand() % 10];
	nrand = nrand.substr(0, 7);
	z = this->newZombie(nrand);
	z->announce();
	delete (z);
}
