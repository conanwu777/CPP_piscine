#include "Bureaucrat.hpp"

int main () {
	try {
		Bureaucrat B("Joe", 100);
		std::cout << B;
		Bureaucrat C("Jim", 151);
		std::cout << C;
		Bureaucrat D("Dan", 0);
		std::cout << D;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try {
		Bureaucrat B("Joe", 2);
		std::cout << B;
		B.incGrade();
		std::cout << B;
		B.incGrade();
		std::cout << B;
		B.incGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
