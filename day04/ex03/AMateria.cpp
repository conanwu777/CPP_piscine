#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria(std::string const & type) : type_(type), xp_(0){}

AMateria::AMateria(){}

AMateria::AMateria(AMateria const & src) {
	this->xp_ = src.getXP();
	this->type_ = src.getType();
}

AMateria & AMateria::operator=(AMateria const & rhs) {
	this->xp_ = rhs.getXP();
	return (*this);
}

AMateria::~AMateria(){}

std::string const & AMateria::getType() const {
	return (this->type_);
}

unsigned int AMateria::getXP() const {
	return (this->xp_);
}

void AMateria::use(ICharacter &) {
	this->xp_ += 10;
}
