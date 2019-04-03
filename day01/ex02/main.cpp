#include "Zombie.hpp"
#include "ZombieEvent.hpp"

int main() {
	Zombie *z1;
	Zombie *z2;
	Zombie *z3;
	Zombie z("StillHere", "Stubborn");
	ZombieEvent event;

	event.setZombieType("Normal");
	z1 = event.newZombie("Joe");
	z1->announce();
	z.announce();
	event.randomChump();
	event.setZombieType("Conehead");
	event.randomChump();
	event.randomChump();
	event.randomChump();
	event.setZombieType("Pogo");
	z2 = event.newZombie("Hippie");
	z2->announce();
	delete (z1);
	delete (z2);
	event.setZombieType("Yeti");
	z3 = event.newZombie("WAAAAA");
	z3->announce();
	delete (z3);
	return 0;
}
