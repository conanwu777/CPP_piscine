#include "Sorcerer.hpp"
#include "Victim.hpp"
# include <iostream>

Sorcerer::Sorcerer(){}

Sorcerer::Sorcerer(Sorcerer const &src) {
	*this = src;
}

Sorcerer::Sorcerer(std::string const n, std::string const t) :
name(n), title(t) {
	std::cout << this->name << ", " << this->title <<", is born !\n";
}

Sorcerer::~Sorcerer() {
	std::cout << this->name << ", " << this->title
	<< ", is dead. Consequences will never be the same !\n";
}

Sorcerer & Sorcerer::operator=(Sorcerer const & rhs) {
	this->name = rhs.getName();
	this->title = rhs.getTitle();
	return (*this);
}

std::ostream & operator<<(std::ostream & ofs, const Sorcerer & s) {
	ofs << "I am " << s.getName() << ", " << s.getTitle() << ", and I like ponies !\n";
	return (ofs);
}

std::string Sorcerer::getName() const {
	return (this->name);
}

std::string Sorcerer::getTitle() const {
	return (this->title);
}

void Sorcerer::polymorph(Victim const & v) {
	v.getPolymorphed();
}
