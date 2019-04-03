#ifndef WIN_HPP
# define WIN_HPP
# include <ncurses.h>
# include <iostream>
# define W 51
# define H 35

class Bullet;
class Enemy;

class Win {
	public:
		WINDOW *w;
		static const int ym = H;
		static const int xm = W;
		int ys;
		int xs;
		int input;
		int life;
		int score;
		Win();
		Win(int yst, int xst);
		~Win();
		Win(Win const &rhs);
		Win &	operator=(Win const &rhs);
		void	generateBG();
		void	obtainInput();
		int		fetchInput() const;
		void	update();
		void	updateEnemies();
		void	updateBullets();
		void	addBullet(Bullet* b);
		void	deleteBullet(Bullet* b);
		void	addEnemy(Enemy* e);
		Enemy*	enemies[H][W];
		char	BG[H][W];
	private:
		Bullet** bullets;
};

#endif