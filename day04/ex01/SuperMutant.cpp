#include "Enemy.hpp"
#include "SuperMutant.hpp"
#include <iostream>

SuperMutant::SuperMutant() : Enemy(170, "Super Mutant"){
	std::cout << "Gaaah. Me want smash heads !\n";}

SuperMutant::~SuperMutant() {
	std::cout << "Aaargh ...\n";}

void SuperMutant::takeDamage(int n) {
	Enemy::takeDamage(n - 3);}
