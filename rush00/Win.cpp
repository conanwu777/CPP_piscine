#include "Win.hpp"
#include "Bullet.hpp"
#include "Enemy.hpp"
#include "PEnemy.hpp"
#include "LEnemy.hpp"
#include <ncurses.h>
#include <iostream>

Win::Win(int yst, int xst) : ys(yst), xs(xst),
life(3), score(0) {
	this->w = newwin(ym, xm, ys, xs);
	box(this->w, 0, 0);
	keypad(this->w, true);
	this->bullets = new Bullet*[ym + 1];
	for (int i = 0; i <= ym; i++)
		this->bullets[i] = NULL;
	for (int i = 0; i < ym; i++)
		for (int j = 0; j < xm; j++)
		{
			this->BG[i][j] = (rand() % 50 ? ' ' : '.'); 
			mvwaddch(this->w, i, j, this->BG[i][j]);
			this->enemies[i][j] = NULL;
		}
}

Win::~Win() {
	for (int i = 0; i < ym; i++)
		if (this->bullets[i])
			delete this->bullets[i];
	for (int i = 0; i < ym; i++)
		for (int j = 0; j < xm; j++)
			if (this->enemies[i][j])
				delete this->enemies[i][j];
	delete bullets;
}

Win::Win(Win const &rhs){
	*this = rhs;}

Win		&Win::operator=(Win const &rhs)
{
	if (this != &rhs)
	{
		this->w = rhs.w;
		this->ys = rhs.ys;
		this->xs = rhs.xs;
		this->input = rhs.input;
	}
	return (*this);
}

void Win::obtainInput() {
	this->input = wgetch(this->w);}

int Win::fetchInput(void) const{
	return (this->input);}

void Win::update() {
	updateBullets();
	updateEnemies();
	mvwprintw(this->w, this->ym - 2, 2,
		"Life: %d   Score: %d  ", this->life, this->score);
	mvwprintw(this->w, this->ym - 2, this->xm - 20, "Press 'Q' to exit");
}

void	Win::updateBullets() {
	int y;
	int x;
	Enemy *e;

	for (int i = 0; i < ym; i++)
		if (this->bullets[i])
		{
			y = this->bullets[i]->getY();
			x = this->bullets[i]->getX();
			if (y > 1 && y < this->ym - 1 &&
				x > 1 && x < this->xm - 1 &&
				(e = this->enemies[y][x]))
			{
				score += 1;
				deleteBullet(this->bullets[i]);
				e->die();
			}
			if (this->bullets[i])
				this->bullets[i]->move();
		}
}

void	Win::updateEnemies()
{
	Enemy *e;
	int r;
	
	for (int i = ym - 2; i >= 0; i--)
		for (int j = 0; j < xm / 2; j++)
		{
			if ((i <= 0 || i >= ym - 1 || j <= 0 || j > xm / 2 - 1)
				&& this->enemies[i][2 * j])
			{
				this->enemies[i][2 * j]->die();
				this->enemies[i][2 * j] = NULL;
			}
			else if (this->enemies[i][2 * j])
				this->enemies[i][2 * j]->move();
		}
	if ((r = rand()) % 10 < 2)
	{
		if (r % 10 == 0)
			e = new PEnemy(*this, 1, 2 * (r % (xm / 2 - 2) + 1));
		else
			e = new Enemy(*this, 1, 2 * (r % (xm / 2 - 2) + 1));
		this->addEnemy(e);
	}
	else if (r % 42 == 1 && 3 <= r % (xm / 2 - 2) + 1 && r % (xm / 2 - 2) + 1 <= xm / 2 - 3)
	{
		e = new LEnemy(*this, r % (ym - 20) + 5, 2 * (r % (xm / 2 - 2) + 1));
		this->enemies[e->getY()][e->getX() - 1] = e;
		this->enemies[e->getY()][e->getX()] = e;
		this->enemies[e->getY()][e->getX() + 1] = e;
		e->display();
	}
}

void	Win::deleteBullet(Bullet *b)
{
	int			idx = b->getIdx();

	delete this->bullets[idx];
	mvwaddch(w, this->bullets[idx]->getY(), this->bullets[idx]->getX(), ' ');
	this->bullets[idx] = NULL;
}

void Win::addBullet(Bullet* b) {
	for (int i = 0; i < ym; i++)
		if (!this->bullets[i])
		{
			b->setIdx(i);
			this->bullets[i] = b;
			break ;
		}
}

void Win::addEnemy(Enemy* e){
	this->enemies[e->getY()][e->getX()] = e;
	e->display();
}

