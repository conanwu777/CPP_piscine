#include "Ice.hpp"
# include <iostream>
# include "AMateria.hpp"
# include "ICharacter.hpp"

Ice::Ice() : AMateria("ice"){}

Ice::~Ice(){}

Ice* Ice::clone() const {
	Ice* tmp = new Ice();
	return (tmp);
}

void Ice::use(ICharacter& target) {
	AMateria::use(target);
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}
