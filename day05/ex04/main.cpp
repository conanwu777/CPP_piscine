#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include "OfficeBlock.hpp"

int main()
{
	Intern      idiotOne;
	Bureaucrat  hermes = Bureaucrat("Hermes Conrad", 37);
	Bureaucrat  bob = Bureaucrat("Bobby Bobson", 123);
	OfficeBlock ob;
	ob.setIntern(idiotOne);
	ob.setSigner(bob);
	ob.setExecutor(hermes);
	
	try
	{
		ob.doBureaucracy("mutant pig termination", "Pigley");
	}
	catch (OfficeBlock::NoInternException &e)
	{
		std::cout << "OfficeBlock not functional because "
		<< e.what() << std::endl;
	}
	catch (OfficeBlock::NoSignerException &e)
	{
		std::cout << "OfficeBlock not functional because "
		<< e.what() << std::endl;
	}
	catch (OfficeBlock::NoExcException &e)
	{
		std::cout << "OfficeBlock not functional because "
		<< e.what() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "Bureaucracy cannot be done because "
		<< e.what() << std::endl;
	}


	OfficeBlock ob2;
	try
	{
		ob2.doBureaucracy("mutant pig termination", "Pigley");
	}
	catch (std::exception & e)
	{
		std::cout << "Bureaucracy cannot be done because "
		<< e.what() << std::endl;
	}

	try
	{
		ob.doBureaucracy("shrubbery creation", "Field");
	}
	catch (std::exception & e)
	{
		std::cout << "Bureaucracy cannot be done because "
		<< e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		ob.doBureaucracy("robotomy request", "Dan");
	}
	catch (std::exception & e)
	{
		std::cout << "Bureaucracy cannot be done because "
		<< e.what() << std::endl;
	}

}