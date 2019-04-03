#include <iostream>

int main() {
	std::string str = "HI THIS IS BRAIN";
	std::string *ptr;
	std::string &ref = str;

	*ptr = str;
	std::cout << *ptr << std::endl;
	std::cout << ref << std::endl;
	return 0;
}
