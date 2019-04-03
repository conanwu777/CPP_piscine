#include <iostream>
#include "Type.hpp"

Base* generate(void) {
	static int st = 0;
	int r;

	if (st == 0)
		srand(time(NULL));
	st = 1;
	r = rand();
	if (r % 3 == 0)
		return (new A());
	else if (r % 3 == 1)
		return (new B());
	else
		return (new C());
}

void identify_from_pointer(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A\n";
	else if (dynamic_cast<B*>(p))
		std::cout << "B\n";
	else if (dynamic_cast<C*>(p))
		std::cout << "C\n";
	else
		std::cout << "None\n";
}

void identify_from_reference(Base& p) {
	if (dynamic_cast<A*>(&p))
		std::cout << "A\n";
	else if (dynamic_cast<B*>(&p))
		std::cout << "B\n";
	else if (dynamic_cast<C*>(&p))
		std::cout << "C\n";
	else
		std::cout << "None\n";
}

int main(){
	Base *p = generate();
	identify_from_pointer(p);
	identify_from_reference(*p);
	return 0;
}
