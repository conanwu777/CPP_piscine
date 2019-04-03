#include "Brain.hpp"
#include <iostream>
#include <sstream>

Brain::Brain(void) {}

Brain::~Brain(void) {}

std::string Brain::identify(void) const {
	std::ostringstream ofs;
	std::string str;

	ofs << std::hex << this;
	str = ofs.str();
	return (str);
}
