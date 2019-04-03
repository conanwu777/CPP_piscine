#ifndef BENEMY_HPP
# define BENEMY_HPP
# include "Enemy.hpp"

# define CYCLE_END 20

class BEnemy : public Enemy
{
	public:
		BEnemy();
		virtual ~BEnemy();
		BEnemy(Win &w, int y, int x);
		BEnemy(Enemy const &src);
		void			move();

	protected:
		static const int	_cycle = CYCLE_END;
		int					_itr;
};

#endif