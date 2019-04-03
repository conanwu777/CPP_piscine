#ifndef SQUARD_HPP
# define SQUARD_HPP
# include "ISpaceMarine.hpp"

class Squad : public ISquad
{
		ISpaceMarine** units;
		int count;
	public:
		Squad();
		Squad(Squad & src);
		~Squad();
		Squad & operator=(Squad const & rhs);
		int getCount() const;
		ISpaceMarine* getUnit(int) const;
		int push(ISpaceMarine*);
};

#endif