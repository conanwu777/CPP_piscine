#include "Bullet.hpp"
#include "Thing.hpp"
#include <ncurses.h>
#include <iostream>

void Bullet::move() {
	this->_ny = this->_y - 1;
	if (this->_ny > 0)
		this->display();
	else
	{
		mvwaddch(this->_wp->w, this->_y, this->_x, ' ');
		this->_wp->deleteBullet(this);
	}
}

Bullet::Bullet(Win &w, int y, int x) :
	Thing(w, y, x, '|'), _idx(-1) {}

Bullet::~Bullet(){};

void			Bullet::onContact(){
	this->_wp->deleteBullet(this);
}

int				Bullet::getIdx()
{
	return (this->_idx);
}

void			Bullet::setIdx(int idx)
{
	this->_idx = idx;
}

void			Bullet::die()
{
	;
}