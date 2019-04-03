#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <iostream>
#include "ICharacter.hpp"

class AMateria;

class Character : public ICharacter {
		std::string name;
	public:
		AMateria* mas[4];
		Character();
		Character(std::string name);
		Character(Character & src);
		~Character();
		Character & operator=(Character const & rhs);
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif
