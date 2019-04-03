#include <ncurses.h>
#include "Player.hpp"
#include "PEnemy.hpp"
#include "Enemy.hpp"
#include "Win.hpp"
#include <stdlib.h>
#include <ctime>

int main()
{
	srand(time(NULL));
	initscr();
	curs_set(0);
	halfdelay(1);
	Win* w = new Win(3, 10);
	refresh();
	start_color();
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_color(6, 824, 999, 266);
	init_pair(2, 6, COLOR_BLACK);
	wattron(w->w, COLOR_PAIR(1) | A_BOLD);
	Player* p = new Player(*w, w->ym - 5, w->xm / 2 - 1, 'A');
	while (w->input != 'q')
	{
		w->obtainInput();
		p->move();
		w->update();
	}
	endwin();
	

	return 0;
}
