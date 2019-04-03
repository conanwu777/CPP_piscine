#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource(){
	for (int i = 0; i < 4; i++)
	this->mas[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource & src){
	*this = src;
}

MateriaSource & MateriaSource::operator=(MateriaSource const & rhs) {
	for (int i = 0; i < 4; i++)
	{
		if (this->mas[i])
			delete this->mas[i];
		this->mas[i] = rhs.mas[i]->clone();
	}
	return *this;
}

MateriaSource::~MateriaSource() {}

void MateriaSource::learnMateria(AMateria* m) {
	for (int i = 0; i < 4; i++)
		if (!this->mas[i])
		{
			this->mas[i] = m;
			break ;
		}
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	AMateria* t;

	for (int i = 0; i < 4; i++)
		if (this->mas[i] && this->mas[i]->getType() == type)
		{
			t = this->mas[i]->clone();
			return (t);
		}
	return (NULL);
}
