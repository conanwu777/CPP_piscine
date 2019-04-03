#include "TacticalMarine.hpp"

TacticalMarine::TacticalMarine(){
	std::cout << "Tactical Marine ready for battle\n";
}

TacticalMarine::TacticalMarine(TacticalMarine &){
	TacticalMarine();
}

TacticalMarine::~TacticalMarine(){
	std::cout << "Aaargh ...\n";
}

TacticalMarine & TacticalMarine::operator=(TacticalMarine const &) {
	return (*this);
}

TacticalMarine* TacticalMarine::clone() const {
	TacticalMarine* t = new TacticalMarine;
	return t;
}

void TacticalMarine::battleCry() const{
	std::cout << "For the holy PLOT !\n";
}

void TacticalMarine::rangedAttack() const {
	std::cout << "* attacks with bolter *\n";
}

void TacticalMarine::meleeAttack() const {
	std::cout << "* attacks with chainsword *\n";
}
