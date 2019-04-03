#include "AMateria.hpp"
#include "Cure.hpp"
#include <iostream>

class AMateria;
class ICharacter;

Cure::Cure() : AMateria("cure"){}

Cure::~Cure(){}

Cure* Cure::clone() const {
	Cure* tmp = new Cure();
	return (tmp);
}

void Cure::use(ICharacter& target) {
	AMateria::use(target);
	std::cout << "* heals " << target.getName() << "’s wounds *\n";
}
