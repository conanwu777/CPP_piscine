#ifndef WEAPON_HPP
#define WEAPON_HPP
#include <iostream>

class Weapon {
	const std::string *_type;
public:
	Weapon(const std::string t);
	~Weapon(void);
	const std::string &getType(void) const;
	void setType(const std::string str);
};

#endif