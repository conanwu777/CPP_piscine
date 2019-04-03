#ifndef BULLET_HPP
# define BULLET_HPP
# include "Thing.hpp"
# include "Win.hpp"
# include <ncurses.h>
# include <iostream>

class Bullet : public Thing
{
	public:
		Bullet(Win &w, int y, int x);
		virtual ~Bullet();
		void move();
		void			onContact();
		void			die();

		int				getIdx();
		void			setIdx(int idx);

	protected:
		int				_idx;
};

#endif