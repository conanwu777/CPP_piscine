#include "Pony.hpp"

Pony::Pony(std::string n, bool u, bool p, std::string c) :
	name(n), unicorn(u), pegasus(p), color(c) {}

Pony::~Pony() {
	std::cout << this->name << " magically disappeared" << std::endl << std::endl;
}

void Pony::intro(void) const {
	std::cout << "My name is " << this->name << std::endl;
	std::cout << "I am ";
	if (!this->unicorn)
		std::cout << "not ";
	std::cout << "an unicorn." << std::endl;
	std::cout << "I am ";
	if (!this->pegasus)
		std::cout << "not ";
	std::cout << "a pegasus." << std::endl;
	std::cout << "I am " << this->color << std::endl << std::endl;
}
