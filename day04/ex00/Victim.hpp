#ifndef VICTIM_H
# define VICTIM_H
# include <iostream>

class Victim {
protected:
	std::string name;
	Victim(void);
public:
	Victim(Victim const &src);
	Victim(std::string const name);
	virtual~Victim(void);
	Victim & operator=(Victim const & rhs);

	std::string getName() const;

	virtual void getPolymorphed() const;
};

std::ostream & operator<<(std::ostream & ofs, const Victim & s);

#endif
