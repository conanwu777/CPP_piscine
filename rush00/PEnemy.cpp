#include "PEnemy.hpp"
#include "Win.hpp"
#include <ncurses.h>

PEnemy::PEnemy(Win &w, int y, int x) : Enemy(w, y, x)
{
	this->_hp = 3;
	this->_c = 'o';
	this->_itr = 0;
	this->_updatePeriod = 8;
}

PEnemy::~PEnemy() {}

void			PEnemy::move()
{
	if (!this->_dead && _count % _updatePeriod == 0)
	{	
		if (!this->_wp->enemies[this->_y][this->_x + 2] &&
			this->_itr < _cycle / 2  &&
			this->_nx + 3 < W)
			this->_nx += 2;
		else if (!this->_wp->enemies[this->_y + 1][this->_x - 2] &&
			this->_itr >= _cycle / 2 &&
			this->_nx - 2 > 0)
			this->_nx -= 2;
		this->_ny += 1;
		this->_itr++;
		if (this->_itr == this->_cycle)
			this->_itr = 0;
		if (_ny >= this->_wp->ym - 1 || this->_wp->enemies[this->_ny][this->_nx]
			|| this->_nx <= 2 || this->_nx >= this->_wp->xm - 2)
		{
			this->die();
			return ;
		}
		this->_wp->enemies[this->_ny][this->_nx] = this->_wp->enemies[this->_y][this->_x];
		this->_wp->enemies[this->_y][this->_x] = NULL;
		this->display();
	}
	_count++;
}
