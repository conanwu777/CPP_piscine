#include "ISquad.hpp"
#include "Squad.hpp"
#include "ISpaceMarine.hpp"

Squad::Squad() : units(NULL), count(0){}

Squad::Squad(Squad & src) : units(NULL), count(0){
	*this = src;
}

Squad::~Squad(){
	for (int i = 0; i < this->count; i++) {
		delete this->units[i];
	}
	delete this->units;
}

Squad & Squad::operator=(Squad const & rhs) {
	if (this->units)
	{
		for (int i = 0; i < this->count; i++) {
			delete this->units[i];
		}
		delete this->units;
	}
	this->count = rhs.getCount();
	this->units = new ISpaceMarine*[rhs.getCount()];
	for (int i = 0; i < this->count; i++) {
		this->units[i] = rhs.getUnit(i)->clone();
	}
	return (*this);
}

int Squad::getCount() const {
	return (this->count);
}

ISpaceMarine* Squad::getUnit(int i) const {
	if (0 <= i && i < this->count)
		return (this->units[i]);
	return (NULL);
}

int Squad::push(ISpaceMarine* p) {
	if (!p)
		return this->count;
	for (int i = 0; i < this->count; i++) {
		if (this->units[i] == p)
			return this->count;
	}
	ISpaceMarine** tmp = new ISpaceMarine*[this->count + 1];
	for (int i = 0; i < this->count; i++) {
		tmp[i] = this->units[i];
	}
	tmp[this->count] = p;
	delete this->units;
	this->count++;
	this->units = tmp;
	return this->count;
}
