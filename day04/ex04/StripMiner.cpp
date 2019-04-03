#include "StripMiner.hpp"
#include "IMiningLaser.hpp"
#include <iostream>

StripMiner::StripMiner(){}

StripMiner::StripMiner(StripMiner & src) {
	*this = src;
}

StripMiner::~StripMiner(){}

StripMiner & StripMiner::operator=(StripMiner const & ){
	return (*this);
}

void StripMiner::mine(IAsteroid* a) {
	std::cout << "* strip mining ... got " << a->beMined(this) << " ! *\n";
}
