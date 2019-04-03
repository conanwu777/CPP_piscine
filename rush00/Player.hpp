#ifndef PLAYER_HPP
# define PLAYER_HPP
# include "Thing.hpp"
# include "Win.hpp"
# include <ncurses.h>
# include <iostream>

class Player : public Thing
{
	public:
		Player();
		Player(Win &w, int y, int x, char c);
		Player(Player const &p);
		Player &			operator=(Player const & rhs);
		virtual ~Player();
		void	move();
		void	act();
		void	display();
		void	die();
		void	resetPos();
};

#endif