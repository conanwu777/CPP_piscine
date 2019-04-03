#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include "OfficeBlock.hpp"
#include "CentralBureaucracy.hpp"

int main()
{
	CentralBureaucracy FT;
	std::string name;
	int g;
	char c;

	for (int i = 0; i < 42; i++)
	{
		c = 'A' + (rand() % 26);
		name = "Gaetan";
		name[0] = c;
		g = rand() % 100 + 1;
		FT.addBureaucrat(new Bureaucrat(name, g));
	}
	for (int i = 0; i < 100; i++)
	{
		c = 'A' + (rand() % 26);
		name = "Dan";
		name[0] = c;
		FT.queueUp(name);
	}
	FT.doBureaucracy();

}