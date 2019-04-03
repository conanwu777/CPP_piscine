#include "Peon.hpp"
#include "Peon.hpp"
# include <iostream>

Peon::Peon(std::string const n) : Victim(n) {
	this->name = n;
	std::cout << "Zog zog.\n";
}

Peon::Peon(Peon & src){
	*this = src;
	std::cout << "Zog zog.\n";
}

Peon::~Peon() {
	std::cout << "Bleuark...\n";
}

void Peon::getPolymorphed() const {
	std::cout << this->name << " has been turned into a pink pony !\n";
}
