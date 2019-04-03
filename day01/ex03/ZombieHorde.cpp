#include "Zombie.hpp"
#include "ZombieHorde.hpp"
#include <iostream>

ZombieHorde::ZombieHorde(int N) {
	std::string nrand;
	std::string al = "@#$&*().!>";
	int c = 0;
	int i;

	this->_num = N;
	this->_horde = new Zombie[N];
	srand(time(NULL));
	while (c < N) {
		nrand = nrand.substr(0, 0);
		i = -1;
		while (++i < 7)
			nrand += al[rand() % 10];
		nrand = nrand.substr(0, 7);
		this->_horde[c].name = nrand;
		this->_horde[c].type = "Horde";
		c++;
	}
}

ZombieHorde::~ZombieHorde(void) {
	delete [] this->_horde;
}

void ZombieHorde::announce(void) {
	Zombie *z;
	int i = 0;

	z = this->_horde;
	while (i < this->_num)
	{
		z[i].announce();
		i++;
	}	
}
