#include "Character.hpp"
#include "AWeapon.hpp"
#include "Enemy.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "SuperMutant.hpp"
#include "RadScorpion.hpp"

#include <iostream>

int main() {
		Character* zaz = new Character("zaz");
		Character* zaz2 = new Character(*zaz);
		std::cout << *zaz;
		RadScorpion* b = new RadScorpion();
		PlasmaRifle* pr = new PlasmaRifle();
		PowerFist* pf = new PowerFist();
		Enemy* b2 = new RadScorpion(*b);
		AWeapon* pr2 = new PlasmaRifle(*pr);
		AWeapon* pf2 = new PowerFist(*pf);
		zaz->equip(pr);
		std::cout << *zaz;
		zaz->equip(pr2);
		std::cout << *zaz;
		zaz->equip(pf);
		std::cout << *zaz;
		zaz->equip(pf2);
		zaz->attack(b);
		std::cout << *zaz;
		zaz->attack(b2);
		std::cout << *zaz;
		zaz->equip(pr);
		std::cout << *zaz;
		zaz->attack(b);
		std::cout << *zaz;
		zaz->attack(b);
		std::cout << *zaz;
		zaz2->attack(b);
		std::cout << "copy of zaz is unchanged\n";
		std::cout << *zaz2;
		return 0; 
}