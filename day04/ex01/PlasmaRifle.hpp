#ifndef PLASMARIFLE_H
# define PLASMARIFLE_H
#include "AWeapon.hpp"
#include <iostream>

class PlasmaRifle : public AWeapon {
	public:
		PlasmaRifle();
		~PlasmaRifle();
		void attack() const;
};

#endif
