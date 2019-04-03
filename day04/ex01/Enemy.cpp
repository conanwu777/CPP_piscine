#include "Enemy.hpp"
#include <iostream>

Enemy::Enemy(int hp, std::string const & type) :
hp(hp), type(type){}

Enemy::Enemy(){}

Enemy::Enemy(Enemy const & src){
	*this = src;
}

Enemy::~Enemy(){}

Enemy & Enemy::operator=(Enemy const & rhs) {
	this->type = rhs.getType();
	this->hp = rhs.getHP();
	return (*this);
}

std::string const Enemy::getType() const {
	return (this->type);
}

int Enemy::getHP() const {
	return (this->hp);
}

void Enemy::takeDamage(int n) {
	if (n <= 0)
		return ;
	if (this->hp >= n)
		this->hp -= n;
	else
		this->hp = 0;
}
