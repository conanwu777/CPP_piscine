#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <iostream>

class Zombie {
public:
	std::string name;
	std::string type;
	Zombie(void);
	~Zombie(void);
	void announce(void) const;
};

#endif