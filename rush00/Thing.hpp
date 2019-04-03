#ifndef Thing_HPP
# define Thing_HPP
# include "Win.hpp"
# include <ncurses.h>
# include <iostream>

class Win;

class Thing {
		Thing(Thing & src);
	public:
		Thing();
		Thing(Win &w, int y, int x, char c);
		Thing & operator=(Thing const & rhs);
		~Thing();
		virtual void	display();
		virtual void	die() = 0;

		bool			isDead();
		Win *			getWin() const;
		int				getX() const;
		int				getY() const;
		int				getNextX() const;
		int				getNextY() const;
		char			getChar() const;

		void			setX(int x);
		void			setY(int y);
		void			setNextX(int nx);
		void			setNextY(int ny);
		void			setChar(char c);


	protected:
		Win			*_wp;
		int			_y;
		int			_x;
		int			_ny;
		int			_nx;
		char		_c;
		bool		_dead;
};

#endif
