#ifndef ENEMY_H
# define ENEMY_H
# include <iostream>

class Enemy {
	private:
		int hp;
		std::string type;
	public:
		Enemy(int hp, std::string const & type);
		Enemy();
		Enemy(Enemy const & src);
		virtual ~Enemy();
		Enemy & operator=(Enemy const & rhs);
		std::string const getType() const;
		int getHP() const;
		virtual void takeDamage(int);
};

#endif
