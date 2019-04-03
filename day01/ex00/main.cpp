#include "Pony.hpp"

void ponyOnTheHeap(std::string n, bool u, bool p, std::string c)
{
	Pony *pony = new Pony(n, u, p, c);

	std::cout << "There is a pony on the heap, she said:" << std::endl;
	pony->intro();
	delete pony;
}

void ponyOnTheStack(std::string n, bool u, bool p, std::string c)
{
	Pony pony(n, u, p, c);

	std::cout << "There is a pony on the stack, she said:" << std::endl;
	pony.intro();
}

int main() {
	ponyOnTheHeap("Fluttershy", 0, 1, "yellow and pink");
	ponyOnTheStack("Rarity", 1, 0, "white and purple");
	return 0;
}