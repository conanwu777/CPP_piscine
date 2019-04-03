#ifndef PEON_H
# define PEON_H
# include "Victim.hpp"
# include <iostream>

class Peon : public Victim {
public:
	Peon(std::string const name);
	virtual~Peon(void);
	Peon(Peon & src);
	void getPolymorphed() const;
};

#endif
