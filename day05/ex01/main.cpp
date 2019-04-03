#include "Bureaucrat.hpp"

int main () {
	try {
		Form f("Form", 50, 50);
		std::cout << f;
		Form g("Form", 0, 50);
		std::cout << g;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		Bureaucrat B("Joe", 100);
		std::cout << B;
		Form f1("Form 1", 56, 70);
		std::cout << f1;
		B.signForm(&f1);
		std::cout << f1;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		Bureaucrat C("Joe", 10);
		std::cout << C;
		Form f2("Form 1", 56, 70);
		std::cout << f2;
		C.signForm(&f2);
		std::cout << f2;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
