#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main () {
	Intern  someRandomIntern;
	Form*   rrf;

	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	std::cout << *rrf;
	delete rrf;
	rrf = someRandomIntern.makeForm("shrubbery creation", "Field");
	std::cout << *rrf;
	delete rrf;
	rrf = someRandomIntern.makeForm("presidential pardon", "Conan");
	std::cout << *rrf;
	delete rrf;
	rrf = someRandomIntern.makeForm("Random Form", "Conan");
	delete rrf;
}
