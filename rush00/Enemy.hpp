#ifndef ENEMY_HPP
# define ENEMY_HPP
# include "Thing.hpp"


class Enemy : public Thing
{
	public:
		Enemy();
		virtual ~Enemy();
		Enemy(Win &w, int y, int x);
		virtual void	move();
		virtual void	die();
		int				getHP() const;
		virtual void	takeDamage(int dmg);

	protected:
		bool				_dead;
		int					_hp;
		int					_updatePeriod;
		int					_count;
};

#endif
