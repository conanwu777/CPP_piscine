#ifndef PONY_HPP
#define PONY_HPP
#include <cstdlib>
#include <iostream>
#include <string>

class Pony {
public:
	std::string name;
	bool unicorn;
	bool pegasus;
	std::string color;
	Pony(std::string name, bool u, bool p, std::string color);
	~Pony(void);
	void intro(void) const;
};

#endif