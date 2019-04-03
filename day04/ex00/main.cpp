#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"
# include <iostream>

int main() {
	Sorcerer robert("Robert", "the Magnificent");
	Victim jim("Jimmy");
	Victim jim2(jim);
	Peon joe("Joe");
	Peon joe2(joe);
	std::cout << robert << jim << joe;
	robert.polymorph(jim);
	robert.polymorph(joe);
	robert.polymorph(joe2);
	robert.polymorph(jim2);
return 0; }