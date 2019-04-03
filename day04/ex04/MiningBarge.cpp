#include "MiningBarge.hpp"
#include <iostream>

MiningBarge::MiningBarge() {
	for (int i = 0; i < 4; i++) {
		this->lasers[i] = NULL;
	}
}

MiningBarge::MiningBarge(MiningBarge & src) {
	*this = src;
}

MiningBarge::~MiningBarge() {
	for (int i = 0; i < 4; i++) {
		if (this->lasers[i]) {
			this->lasers[i] = NULL;
		}
	}
}

MiningBarge & MiningBarge::operator=(MiningBarge const & rhs) {
	for (int i = 0; i < 4; i++) {
		this->lasers[i] = rhs.lasers[i];
	}
	return (*this);
}
		

void MiningBarge::equip(IMiningLaser* l) {
	for (int i = 0; i < 4; i++) {
		if (!this->lasers[i])
		{
			this->lasers[i] = l;
			break ;
		}
	}
}

void MiningBarge::mine(IAsteroid* a) const {
	for (int i = 0; i < 4; i++)
	{
		if (this->lasers[i])
			this->lasers[i]->mine(a);
	}
}
