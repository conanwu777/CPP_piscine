#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main () {
	ShrubberyCreationForm s("EmptyField");
	std::cout << s;
	Bureaucrat M("Michael", 140);
	std::cout << M;
	M.executeForm(s);
	M.signForm(&s);
	M.executeForm(s);
	Bureaucrat G("Gatan", 4);
	G.executeForm(s);

	RobotomyRequestForm r("Dan");
	std::cout << r;
	Bureaucrat T("Tony", 70);
	std::cout << T;
	T.signForm(&r);
	T.executeForm(r);
	std::cout << G;
	G.executeForm(r);

	PresidentialPardonForm p("Conan");
	G.signForm(&p);
	std::cout << p;
	G.executeForm(p);
	return 0;
}
