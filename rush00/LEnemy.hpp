#ifndef LENEMY_HPP
# define LENEMY_HPP
# include "Enemy.hpp"

class LEnemy : public Enemy
{
	public:
		LEnemy();
		virtual ~LEnemy();
		LEnemy(Win &w, int y, int x);
		LEnemy(Enemy const &src);
		void display();
		void move();
		void die();
};

#endif