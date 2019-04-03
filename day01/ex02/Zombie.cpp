#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string n, std::string t) : name(n), type(t) {}

Zombie::~Zombie(void){
	std::cout << this->name << " is destroyed" << std::endl;
}

void Zombie::announce(void) const {
	std::cout << this->type << " zombie " << this->name << " approaches, you hear: " << std::endl;
	std::cout << "Braiiiiiiinnnssss..." << std::endl;
}
