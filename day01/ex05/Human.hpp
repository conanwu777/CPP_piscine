#ifndef HUMAN_HPP
#define HUMAN_HPP
#include "Brain.hpp"

class Human {
public:
	Brain const b;
	int const lifetime;

	Human(void);
	~Human(void);
	const Brain &getBrain(void) const;
	std::string identify(void) const;
};

#endif