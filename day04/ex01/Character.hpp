#ifndef CHARACTER_H
# define CHARACTER_H
# include "AWeapon.hpp"
# include "Enemy.hpp"
# include <iostream>

class Character
{
	private:
		std::string name;
		Character();
	public:
		int ap;
		AWeapon *weapon;
		Character(std::string const & name);
		Character(Character const & src);
		~Character();
		Character & operator=(Character const & rhs);
		void recoverAP();
		void equip(AWeapon*);
		void attack(Enemy*);
		std::string const getName() const;
};

std::ostream & operator<<(std::ostream & ofs, const Character & s);

#endif
