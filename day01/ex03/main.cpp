#include "Zombie.hpp"
#include "ZombieHorde.hpp"

int main() {
	ZombieHorde h2(3);

	ZombieHorde *h1 = new ZombieHorde(7);
	h1->announce();
	delete(h1);
	h2.announce();
	return 0;
}
