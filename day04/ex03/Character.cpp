#include "ICharacter.hpp"
#include "Character.hpp"

Character::Character() {}

Character::Character(std::string name) : name(name) {
	for (int i = 0; i < 4; i++)
		this->mas[i] = NULL;
}

Character::Character(Character & src) {
	*this = src;
}

Character::~Character() {
	for (int i = 0; i < 4; i++)
		if (this->mas[i])
			delete this->mas[i];
}

Character & Character::operator=(Character const & rhs) {
	this->name = rhs.getName();
	for (int i = 0; i < 4; i++)
	{
		if (this->mas[i])
			delete this->mas[i];
		if (rhs.mas[i])
			this->mas[i] = rhs.mas[i]->clone();
		else
			this->mas[i] = NULL;
	}
	return *this;
}

std::string const & Character::getName() const {
	return (this->name);
}

void Character::equip(AMateria* m) {
	for (int i = 0; i < 4; i++)
		if (this->mas[i] == NULL)
		{
			this->mas[i] = m;
			return ;
		}
}

void Character::unequip(int idx) {
	if (0 <= idx && idx < 4 && this->mas[idx])
		this->mas[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx >= 4 || !this->mas[idx])
		return ;
	this->mas[idx]->use(target);
}
