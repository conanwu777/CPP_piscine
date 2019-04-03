#include "RobotomyRequestForm.hpp"
#include <ctime>
#include <stdlib.h>

RobotomyRequestForm::RobotomyRequestForm(std::string t) :
Form("RobotomyRequestForm", 72, 45) {
	this->target = t;
}

void RobotomyRequestForm::action(void) const {
	if (rand() % 2 == 0)
	{
		std::cout << "Bzzzzz...KATAKATA Bzzzzzzzzzzzzzzzz\n"
			<< this->target << " has been successfully robotomized!!!\n";
	}
	else
	{
		std::cout << "Bzzzzz...KATAKATA Bzzzzzzzzzzzzzzzz\n"
		<< "Robotomization failed and "
			<< this->target << " is no longer with us...RIP\n";
	}
}
