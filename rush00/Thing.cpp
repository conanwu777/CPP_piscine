#include "Thing.hpp"
#include <ncurses.h>
#include <iostream>

Thing::Thing(){}

Thing::Thing(Thing & src){
	*this = src;}

Thing::~Thing(){}

Thing & Thing::operator=(Thing const & rhs){
	if (this != &rhs) {
		this->_wp = rhs.getWin();
		this->_y = rhs.getY();
		this->_x = rhs.getX();
		this->_c = rhs.getChar();
	}
	return (*this);
}

Thing::Thing(Win &w, int y, int x, char c) :
	_wp(&w), _y(y), _x(x), _ny(y), _nx(x), _c(c) {
		this->_dead = false; }

void Thing::display() {
	wattroff(this->_wp->w, COLOR_PAIR(1));
	mvwaddch(this->_wp->w, this->_y, this->_x, this->_wp->BG[this->_y][this->_x]);
	wattron(this->_wp->w, COLOR_PAIR(1));
	if (1 <= this->_ny && this->_ny <= this->_wp->ym - 2
		&& 1 <= this->_nx && this->_nx <= this->_wp->xm - 1)
		mvwaddch(this->_wp->w, this->_ny, this->_nx, this->_c);
	this->_y = this->_ny;
	this->_x = this->_nx;
}

Win				*Thing::getWin() const {
	return (this->_wp); }

int				Thing::getX() const {
	return (this->_x); }

int				Thing::getY() const {
	return (this->_y); }

int				Thing::getNextX() const {
	return (this->_nx); }

int				Thing::getNextY() const {
	return (this->_ny); }

char			Thing::getChar() const {
	return (this->_c); }

void			Thing::setX(int x){
	this->_x = x;}

void			Thing::setY(int y){
	this->_y = y;}

void			Thing::setNextX(int nx){
	this->_nx = nx;}

void			Thing::setNextY(int ny){
	this->_ny = ny;}

void			Thing::setChar(char c){
	this->_c = c;}

bool			Thing::isDead(){
	return this->_dead;}