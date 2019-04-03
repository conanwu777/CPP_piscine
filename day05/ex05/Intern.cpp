#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {}

Intern::Intern(Intern const &){}

Intern::~Intern(){}

Intern & Intern::operator=(const Intern &) {
	return *this;}

Form* Intern::makeForm(const std::string name, const std::string target) const
{
	Form* f = NULL;
	if (name ==  "shrubbery creation")
		f = new ShrubberyCreationForm(target);
	else if (name ==  "robotomy request")
		f = new RobotomyRequestForm(target);
	else if (name == "presidential pardon")
		f = new PresidentialPardonForm(target);
	if (!f)
		throw FormNotExistException();
	std::cout << "Intern creates " << name << " form (sign grade " 
	<< f->getGradeSign() << ", excution grade " << f->getGradeEx()
	<< ") targeted at " << target << std::endl;
	return (f);
}

const char* Intern::FormNotExistException::what() const throw() {
		return ("Form name is not reconized\n");}
