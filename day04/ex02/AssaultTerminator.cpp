#include "AssaultTerminator.hpp"

AssaultTerminator::AssaultTerminator(){
	std::cout << "* teleports from space *\n";
}

AssaultTerminator::AssaultTerminator(AssaultTerminator &){
	AssaultTerminator();
}

AssaultTerminator::~AssaultTerminator(){
	std::cout << "I'll be back ...\n";
}

AssaultTerminator & AssaultTerminator::operator=(AssaultTerminator const &) {
	return (*this);
}

AssaultTerminator* AssaultTerminator::clone() const {
	AssaultTerminator* t = new AssaultTerminator;
	return t;
}

void AssaultTerminator::battleCry() const{
	std::cout << "This code is unclean. PURIFY IT !\n";
}

void AssaultTerminator::rangedAttack() const {
	std::cout << "* does nothing *\n";
}

void AssaultTerminator::meleeAttack() const {
	std::cout << "* attacks with chainfists *\n";
}
