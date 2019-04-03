#include "Enemy.hpp"
#include "RadScorpion.hpp"
#include <iostream>

RadScorpion::RadScorpion() : Enemy(80, "RadScorpion") {
	std::cout << "* click click click *\n";}

RadScorpion::~RadScorpion() {
	std::cout << "* SPROTCH *\n";}
