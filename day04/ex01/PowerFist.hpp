#ifndef POWERFIST_H
# define POWERFIST_H
#include "AWeapon.hpp"
#include <iostream>

class PowerFist : public AWeapon {
	public:
		PowerFist();
		~PowerFist();
		void attack() const;
};

#endif
