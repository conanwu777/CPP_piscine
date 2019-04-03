#include "Human.hpp"

Human::Human(void) : b(Brain()), lifetime(42) {}

Human::~Human(void) {}

std::string Human::identify(void) const {
	std::string res;

	res += (this->b).identify();
	return (res);
}

const Brain &Human::getBrain(void) const {
	return (this->b);
}
