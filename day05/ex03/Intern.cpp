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
	std::string names[3];
	Form* (*f[3])(std::string);
	int i;
	Form* form;

	names[0] = "shrubbery creation";
	names[1] = "robotomy request";
	names[2] = "presidential pardon";

	f[0] = ShrubberyCreationForm::make;
	f[1] = RobotomyRequestForm::make;
	f[2] = PresidentialPardonForm::make;

	for (i = 0; i < 3; i++)
		if (!name.compare(names[i]))
			break ;
	if (i == 3)
	{
		std::cout << "Form name does not exist in Bureaucracy\n";
		return NULL;
	}
	form = f[i](target);
	std::cout << "Intern creates " << name << " form " << std::endl;
	return (form);
}
