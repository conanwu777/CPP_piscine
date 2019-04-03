#include "BEnemy.hpp"
#include "Win.hpp"
#include <ncurses.h>

BEnemy::BEnemy(Win &w, int y, int x) : Enemy(w, y, x)
{
	this->_hp = 100;
	this->_c = '*';
	this->_itr = 0;
	this->_updatePeriod = 1;
}

BEnemy::~BEnemy() {}

void			BEnemy::move()
{
	if (!this->_dead)
	{	
		if (!(this->_dead) && _count % _updatePeriod == 0)
		{	
			this->_ny += 1;
			if (_ny >= this->_wp->ym - 1 || this->_wp->enemies[this->_ny][this->_nx])
			{
				this->die();
				return ;
			}
			if (_ny < this->_wp->ym - 1 && this->_wp->enemies[this->_ny][this->_nx])
				this->_wp->enemies[this->_ny][this->_nx]->die();
			this->_wp->enemies[this->_ny][this->_nx]
			= this->_wp->enemies[this->_y][this->_x];
			this->_wp->enemies[this->_y][this->_x] = NULL;
			this->display();
		}
	}
}
