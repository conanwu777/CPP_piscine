#ifndef PENEMY_HPP
# define PENEMY_HPP
# include "Enemy.hpp"

# define CYCLE_END 20

class PEnemy : public Enemy
{
	public:
		PEnemy();
		virtual ~PEnemy();
		PEnemy(Win &w, int y, int x);
		PEnemy(Enemy const &src);
		void			move();

	protected:
		static const int	_cycle = CYCLE_END;
		int					_itr;
};

#endif