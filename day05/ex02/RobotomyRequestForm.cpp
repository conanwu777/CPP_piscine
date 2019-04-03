#include "RobotomyRequestForm.hpp"
#include <ctime>
#include <stdlib.h>

RobotomyRequestForm::RobotomyRequestForm(std::string t) :
Form("RobotomyRequestForm", 72, 45) {
	this->target = t;
	srand(time(NULL));
}

void RobotomyRequestForm::action(void) const {
	if (rand() % 2)
	{
		std::cout << "Bzzzzz...KATAKATA Bzzzzzzzzzzzzzzzz\n"
			<< this->target << " has been successfully robotomized!!!\n";
	}
	else
	{
		std::cout << "Robotomization failed and "
			<< this->target << " is no longer with us...RIP\n";
	}
}
