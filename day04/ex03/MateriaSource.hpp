#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
		AMateria* mas[4];
	public:
		MateriaSource();
		MateriaSource(MateriaSource & src);
		MateriaSource & operator=(MateriaSource const & rhs);
		~MateriaSource();
		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
};

#endif
