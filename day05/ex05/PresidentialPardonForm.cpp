#include "PresidentialPardonForm.hpp"
#include <ctime>
#include <stdlib.h>

PresidentialPardonForm::PresidentialPardonForm(std::string t) :
Form("PresidentialPardonForm", 25, 5) {
	this->target = t;
}

void PresidentialPardonForm::action(void) const {
	std::cout << this->target << " has been pardoned by Zafod Beeblebrox.\n";
}
