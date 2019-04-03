#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(void) {
	std::cout << "New zombie " << this->name << " is here" << std::endl;
}

Zombie::~Zombie(void){
	std::cout << this->name << " is destroyed" << std::endl;
}

void Zombie::announce(void) const {
	std::cout << this->type << " zombie " <<
		this->name << " approaches. ";
	std::cout << "You hear: Braiiiiiiinnnssss..." << std::endl;
}
