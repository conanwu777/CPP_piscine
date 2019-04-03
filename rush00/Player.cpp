#include "Player.hpp"
#include "Thing.hpp"
#include "Bullet.hpp"
#include "Enemy.hpp"
#include "Win.hpp"
#include <ncurses.h>
#include <iostream>

Player::Player(Win &w, int y, int x, char c) : Thing(w, y, x, c) {
	this->_dead = false;
}

Player::~Player(){};

void Player::move() {
	if (!this->_dead)
	{
		if (this->_wp->input == KEY_UP && this->_y > 1)
			this->_ny = this->_y - 1;
		else if ( this->_wp->input == KEY_DOWN && this->_y < this->_wp->ym - 2)
			this->_ny = this->_y + 1;
		else if ( this->_wp->input == KEY_LEFT && this->_x > 2)
			this->_nx = this->_x - 2;
		else if ( this->_wp->input == KEY_RIGHT && this->_x < this->_wp->xm - 3)
			this->_nx = this->_x + 2;
		this->act();
		this->die();
		this->display();
	}
	else
	{
		int y;
		int x;
		mvwprintw(this->_wp->w, this->_wp->ym / 2 - 1, this->_wp->xm / 2 - 5,
			"Game Over");
		mvwprintw(this->_wp->w, this->_wp->ym / 2, this->_wp->xm / 2 - 12,
			"Press 'R' to Refill Life");
		while (this->_wp->fetchInput() == -1)
			this->_wp->obtainInput();
		if (this->_wp->input == 'r')
		{
			mvwprintw(this->_wp->w, this->_wp->ym / 2 - 1, this->_wp->xm / 2 - 5,
				"         ");
			mvwprintw(this->_wp->w, this->_wp->ym / 2, this->_wp->xm / 2 - 12,
				"                         ");	
			getyx(this->_wp->w, y, x);
			mvwaddch(this->_wp->w, y, x - 1, ' ');
			this->_wp->life = 3;
			this->resetPos();
		}
	}
}

void Player::display() {
	mvwaddch(this->_wp->w, this->_y, this->_x, ' ');
	if (1 <= this->_ny && this->_ny <= this->_wp->ym - 2
		&& 1 <= this->_nx && this->_nx <= this->_wp->xm - 1)
	if (!this->_dead)
		mvwaddch(this->_wp->w, this->_ny, this->_nx, this->_c);
	this->_y = this->_ny;
	this->_x = this->_nx;
}

void Player::act() {
	if (this->_wp->input == ' ')
	{
		Bullet* b = new Bullet(*this->_wp, this->_y - 1, this->_x);
		this->_wp->addBullet(b);
	}
}

void	Player::die()
{
	if (this->_wp->enemies[this->_ny][this->_nx])
	{
		this->_wp->life -= 1;
		this->_wp->enemies[this->_ny][this->_nx]->die();
		if (this->_wp->life <= 0)
		{
			int y;
			int x;
			getyx(this->_wp->w, y, x);
			x -= 1;

			if (x - 1 > 1 && y - 1 > 1)
				mvwaddch(this->_wp->w, y - 1, x - 1, '\\');
			if (y - 1 > 1)
				mvwaddch(this->_wp->w, y - 1, x, '|');
			if (x + 2 < this->_wp->xm && y - 2 > 1)
				mvwaddch(this->_wp->w, y - 1	, x + 1, '/');
			if (x - 2 > 0)
				mvwaddch(this->_wp->w, y, x - 1, '-');
			if (x + 2 < _wp->xm)
				mvwaddch(this->_wp->w, y, x + 1, '-');
			if (x - 1 > 0 && y + 2 < this->_wp->ym)
				mvwaddch(this->_wp->w, y + 1, x - 1, '/');
			if (y + 2 < this->_wp->ym)
				mvwaddch(this->_wp->w, y + 1, x, '|');
			if (x + 2 < this->_wp->xm && y + 2 < this->_wp->ym)
				mvwaddch(this->_wp->w, y + 1, x + 1, '\\');
			this->_dead = true;
		}
	}
}

void			Player::resetPos()
{
	this->_ny = this->_wp->ym - 5;
	this->_nx = this->_wp->xm / 2 - 1;
	this->_dead = false;
	this->_wp->life = 3;
}

