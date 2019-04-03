#ifndef AMATERIA_HPP
#define AMATERIA_HPP
#include <iostream>

class ICharacter;

class AMateria
{
	private:
		std::string type_;
		unsigned int xp_;
	public:
		AMateria(std::string const & type);
		AMateria();
		AMateria(AMateria const & src);
		AMateria & operator=(AMateria const & rhs);
		virtual ~AMateria();
		std::string const & getType() const; //Returns the materia type
		unsigned int getXP() const; //Returns the Materia's XP
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif
