#include "CentralBureaucracy.hpp"
#include "Intern.hpp"
#include <stdlib.h>
#include <ctime>

CentralBureaucracy::CentralBureaucracy() {
	srand(time(NULL));
	for (int i = 0; i < 20; i++)
		obs[i].setIntern(*(new Intern()));
	targets = "";
}

CentralBureaucracy::~CentralBureaucracy() {}

void CentralBureaucracy::addBureaucrat(Bureaucrat* b) {
	for (int i = 0; i < 20; i++)
	{
		if (!obs[i].getSigner())
		{
			obs[i].setSigner(*b);
			return ;
		}
		else if (!obs[i].getExecutor())
		{
			obs[i].setExecutor(*b);
			return ;
		}
	}
	std::cout << "All positions in Central Bureaucracy are currently filled\n";
}

void CentralBureaucracy::queueUp(std::string target) {
	targets = targets + target + (char)1;
}

std::string CentralBureaucracy::getNextTarget(void) {
	int i = 0;
	std::string str;

	while (targets[i] && targets[i] != 1)
		i++;
	str = targets.substr(0, i);
	if (targets[i])
		targets = targets.substr(i + 1, targets.size());
	else
		targets = "";
	return (str);
}

void CentralBureaucracy::doBureaucracy() {
	int r;
	int i;
	std::string form;
	std::string t;
	std::string empty = "";

	i = 0;
	while ((t = getNextTarget()) != empty)
	{
		r = rand();
		if (r % 3 == 0)
			form = "shrubbery creation";
		else if (r % 3 == 1)
			form = "robotomy request";
		else if (r % 3 == 2)
			form = "presidential pardon";
		else
			form = "some random form";
		try
		{
			obs[i].doBureaucracy(form, t);
		}
		catch (std::exception & e)
		{
			std::cout << "Bureaucracy cannot be done because "
			<< e.what() << std::endl;
		}
		i++;
		if (i == 20)
			i = 0;
		std::cout << std::endl;
	}
}
