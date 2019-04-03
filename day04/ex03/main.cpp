#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"

int main() {
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	Character* zaz = new Character("zaz");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	zaz->equip(tmp);
	tmp = src->createMateria("cure");
	zaz->equip(tmp);
	tmp = src->createMateria("ice");
	zaz->equip(tmp);
	ICharacter* bob = new Character("bob");
	std::cout << "zaz carries: 0 Ice, 1 cure, 2 ice\n";
	zaz->use(0, *bob);
	zaz->use(1, *bob);
	zaz->use(2, *bob);
	std::cout << "Made a copy of zaz\n";
	Character* zaz2 = new Character(*zaz);
	std::cout << "zaz unequipped 1 and re-equippe with ice\n";
	tmp = src->createMateria("ice");
	zaz->unequip(1);
	zaz->equip(tmp);
	zaz->use(0, *bob);
	zaz->use(1, *bob);
	zaz->use(2, *bob);
	std::cout << "copy of zaz: still the original\n";
	zaz2->use(0, *bob);
	zaz2->use(1, *bob);
	zaz2->use(2, *bob);
	delete zaz2;
	delete bob;
	delete zaz;
	delete src;
	return 0; 
}
