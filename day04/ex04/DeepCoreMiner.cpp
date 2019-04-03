#include "DeepCoreMiner.hpp"
#include "IMiningLaser.hpp"
#include <iostream>

DeepCoreMiner::DeepCoreMiner() {}

DeepCoreMiner::DeepCoreMiner(DeepCoreMiner & src) {
	*this = src;
}

DeepCoreMiner::~DeepCoreMiner(){}

DeepCoreMiner & DeepCoreMiner::operator=(DeepCoreMiner const & ){
	return (*this);
}

void DeepCoreMiner::mine(IAsteroid* a) {
	std::cout << "* mining deep ... got " << a->beMined(this) << " ! *\n";
}
