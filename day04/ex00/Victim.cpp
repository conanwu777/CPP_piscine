#include "Victim.hpp"
# include <iostream>

Victim::Victim(){
	std::cout << "Some random victim called " << this->name << " just popped !\n";
}

Victim::Victim(Victim const &src) {
	*this = src;
}

Victim::Victim(std::string const n) : name(n) {
	std::cout << "Some random victim called " << this->name << " just popped !\n";
}

Victim::~Victim() {
	std::cout << "Victim " << this->name << " just died for no apparent reason !\n";
}

Victim & Victim::operator=(Victim const & rhs) {
	this->name = rhs.getName();
	return (*this);
}

std::ostream & operator<<(std::ostream & ofs, const Victim & s) {
	ofs << "I'm " << s.getName() << " and I like otters !\n";
	return (ofs);
}

std::string Victim::getName() const {
	return (this->name);
}

void Victim::getPolymorphed() const {
	std::cout << this->name << " has been turned into a cute little sheep !\n";
}
