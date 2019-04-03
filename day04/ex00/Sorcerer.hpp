#ifndef SORCERER_H
# define SORCERER_H
# include "Victim.hpp"
# include <iostream>

class Sorcerer {
	std::string name;
	std::string title;
	Sorcerer(void);
public:
	Sorcerer(Sorcerer const &src);
	Sorcerer(std::string const name, std::string const title);
	~Sorcerer(void);
	Sorcerer & operator=(Sorcerer const & rhs);

	std::string getName() const;
	std::string getTitle() const;

	void polymorph(Victim const &);
};

std::ostream & operator<<(std::ostream & ofs, const Sorcerer & s);

#endif
