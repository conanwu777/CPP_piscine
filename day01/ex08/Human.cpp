#include "Human.hpp"

typedef  void (Human::*function)(std::string const & target);

Human::Human(void) {}
Human::~Human(void) {}

void Human::meleeAttack(std::string const & target) {
	std::cout << "Someone launched a Melee Attack towards "
		<< target << std::endl;
}

void Human::rangedAttack(std::string const & target) {
	std::cout << "Someone launched a Ranged Attack towards "
		<< target << std::endl;
}

void Human::intimidatingShout(std::string const & target) {
	std::cout << "Someone launched an Intimidating Shout towards "
		<< target << std::endl;
}

void Human::action(std::string const & action_name, std::string const & target) {
	void (Human::*f[3])(std::string const & target);
	std::string names[3];
	int i;

	names[0] = "meleeAttack";
	names[1] = "rangedAttack";
	names[2] = "intimidatingShout";
	f[0] = &Human::meleeAttack;
	f[1] = &Human::rangedAttack;
	f[2] = &Human::intimidatingShout;
	for (i = 0; i < 3; i++) {
		if (names[i].compare(action_name) == 0)
			break ;
	}
	if (i < 3)
		(this->*f[i])(target);
}
