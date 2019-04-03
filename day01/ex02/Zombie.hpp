#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <iostream>

class Zombie {
	std::string name;
	std::string type;
public:
	Zombie(std::string n, std::string t);
	~Zombie(void);
	void announce(void) const;
};

#endif