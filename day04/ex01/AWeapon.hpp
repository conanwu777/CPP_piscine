#ifndef AWEAPON_H
# define AWEAPON_H
# include <iostream>

class AWeapon
{
	private:
		std::string name;
		int apcost;
		int damage;
	public:
		AWeapon(std::string const & name, int apcost, int damage);
		AWeapon();
		AWeapon(AWeapon const & src);
		virtual~AWeapon();
		AWeapon & operator=(AWeapon const & rhs);

		std::string const getName() const;
		int getAPCost() const;
		int getDamage() const;

		virtual void attack() const = 0;
};

#endif
