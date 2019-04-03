#include "Enemy.hpp"
#include "BEnemy.hpp"
#include <ncurses.h>

Enemy::Enemy(Win &w, int y, int x) : Thing(w, y, x, '#')
{
	this->_hp = 1;
	this->_dead = false;
	this->_count = 0;
	this->_updatePeriod = 8;
}

Enemy::~Enemy() {}

void	Enemy::die() {
	this->_wp->enemies[this->_y][this->_x] = NULL;
	mvwaddch(this->_wp->w, this->_y, this->_x, ' ');
	delete this;
}

void	Enemy::move()
{
	BEnemy* e;

	if (!(this->_dead) && _count % _updatePeriod == 0)
	{	
		this->_ny += 1;
		if (_ny >= this->_wp->ym - 1 || this->_wp->enemies[this->_ny][this->_nx])
		{
			this->die();
			return ;
		}
		this->_wp->enemies[this->_ny][this->_nx] = this->_wp->enemies[this->_y][this->_x];
		this->_wp->enemies[this->_y][this->_x] = NULL;
		this->display();
		if (rand() % 100 == 0)
		{
			e = new BEnemy(*this->_wp, this->_ny + 1, this->_nx);
			this->_wp->addEnemy(e);
		}
	}
	_count++;
}

void		Enemy::takeDamage(int dmg)
{
	this->_hp -= dmg;
	if (this->_hp <= 0)
	{
		this->_hp = 0;
		this->_dead = true;
	}
}

int		Enemy::getHP() const
{
	return (this->_hp);
}
