#include "AWeapon.hpp"
#include "PlasmaRifle.hpp"
#include <iostream>

PlasmaRifle::PlasmaRifle() : AWeapon("Plasma Rifle", 5, 21){}

PlasmaRifle::~PlasmaRifle() {};

void PlasmaRifle::attack() const {
	std::cout << "* piouuu piouuu piouuu *\n";
}
