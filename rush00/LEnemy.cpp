#include "LEnemy.hpp"
#include "BEnemy.hpp"
#include "Win.hpp"
#include <ncurses.h>

LEnemy::LEnemy(Win &w, int y, int x) : Enemy(w, y, x)
{
	this->_hp = 10;
	this->_c = '+';
	this->_updatePeriod = 1;
}

LEnemy::~LEnemy() {}

void	LEnemy::die() {
	this->_wp->enemies[this->_y - 1][this->_x] = NULL;
	this->_wp->enemies[this->_y + 1][this->_x] = NULL;
	this->_wp->enemies[this->_y][this->_x] = NULL;
	this->_wp->enemies[this->_y][this->_x - 1] = NULL;
	this->_wp->enemies[this->_y][this->_x + 1] = NULL;
	mvwaddch(this->_wp->w, this->_y - 1, this->_x, this->_wp->BG[this->_y - 1][this->_x]);
	mvwaddch(this->_wp->w, this->_y + 1, this->_x, this->_wp->BG[this->_y + 1][this->_x]);
	mvwaddch(this->_wp->w, this->_y, this->_x, this->_wp->BG[this->_y][this->_x]);
	mvwaddch(this->_wp->w, this->_y, this->_x - 1, this->_wp->BG[this->_y][this->_x - 1]);
	mvwaddch(this->_wp->w, this->_y, this->_x + 1, this->_wp->BG[this->_y][this->_x + 1]);
	delete this;
}

void LEnemy::display() {
	if (this->_wp->enemies[_y - 1][_x] && this->_wp->enemies[_y - 1][_x] != this)
		this->_wp->enemies[_y - 1][_x]->die();
	if (this->_wp->enemies[_y + 1][_x] && this->_wp->enemies[_y + 1][_x] != this)
		this->_wp->enemies[_y + 1][_x]->die();
	if (this->_wp->enemies[_y][_x] && this->_wp->enemies[_y][_x] != this)
		this->_wp->enemies[_y][_x]->die();
	if (this->_wp->enemies[_y][_x - 1] && this->_wp->enemies[_y][_x - 1] != this)
		this->_wp->enemies[_y][_x - 1]->die();
	if (this->_wp->enemies[_y][_x + 1] && this->_wp->enemies[_y][_x + 1] != this)
		this->_wp->enemies[_y][_x + 1]->die();
	wattroff(this->_wp->w, COLOR_PAIR(1));
	mvwaddch(this->_wp->w, this->_y - 1, this->_x, this->_wp->BG[this->_y - 1][this->_x]);
	mvwaddch(this->_wp->w, this->_y + 1, this->_x, this->_wp->BG[this->_y + 1][this->_x]);
	mvwaddch(this->_wp->w, this->_y, this->_x, this->_wp->BG[this->_y][this->_x]);
	mvwaddch(this->_wp->w, this->_y, this->_x - 1, this->_wp->BG[this->_y][this->_x - 1]);
	mvwaddch(this->_wp->w, this->_y, this->_x + 1, this->_wp->BG[this->_y][this->_x + 1]);
	wattron(this->_wp->w, COLOR_PAIR(1));
	mvwaddch(this->_wp->w, this->_y - 1, this->_x, this->_c);
	mvwaddch(this->_wp->w, this->_y + 1, this->_x, this->_c);
	mvwaddch(this->_wp->w, this->_y, this->_x, this->_c);
	mvwaddch(this->_wp->w, this->_y, this->_x - 1, this->_c);
	mvwaddch(this->_wp->w, this->_y, this->_x + 1, this->_c);
}

void LEnemy::move()
{
	BEnemy* e;

	if (!(this->_dead) && _count % _updatePeriod == 0)
	{	
		if (rand() % 20 == 0)
		{
			if (this->_wp->enemies[_ny + 2][_nx])
				this->_wp->enemies[_ny + 2][_nx]->die();
			e = new BEnemy(*this->_wp, this->_ny + 2, this->_nx);
			this->_wp->addEnemy(e);
		}
	}
	this->display();
}
