#include "GraphicDisplay.hpp"
#include <iostream>
#include <algorithm>
#define W 300
#define STR mlx_string_put

GraphicDisplay* GraphicDisplay::inst;

extern "C"
{
# include "mlx.h"
}

int		k_control(int key)
{
	if (key == 12)
		exit(1);
	if (key == 18)
		GraphicDisplay::inst->getInfo().at(0)->Switch();
	if (key == 19)
		GraphicDisplay::inst->getInfo().at(1)->Switch();
	if (key == 20)
		GraphicDisplay::inst->getInfo().at(2)->Switch();
	if (key == 21)
		GraphicDisplay::inst->getInfo().at(3)->Switch();
	if (key == 23)
		GraphicDisplay::inst->getInfo().at(4)->Switch();
	if (key == 22)
		GraphicDisplay::inst->getInfo().at(5)->Switch();
	if (key == 26)
		GraphicDisplay::inst->getInfo().at(6)->Switch();
	if (key == 28)
		GraphicDisplay::inst->getInfo().at(7)->Switch();
	return (1);
}

int		exit_x(void){
	exit(1);}

GraphicDisplay::GraphicDisplay(std::vector<IMonitorModule*> info) : info(info)
{
	winHeight = 40;
	for (unsigned int i = 0; i < info.size(); i++)
		if (info.at(i)->onOff())
			winHeight += info.at(i)->getHeight() + 20;
	mlx = mlx_init();
	win = mlx_new_window(mlx, W, winHeight, const_cast<char*>("ft_gkrellm"));
	mlx_key_hook(win, &k_control, (void*)0);
	mlx_hook(win, 17, 1L << 17, exit_x, (void*)0);
	mlx_loop_hook(mlx, &refreshGraphicDisplay, 0);
	GraphicDisplay::inst = this;


	int		db;
	void*	img;
	img = mlx_xpm_file_to_image(mlx, const_cast<char*>("cat.xpm"), &db, &db);
	static_cast<CatModule*>(info.at(7))->cat = mlx_get_data_addr(img, &db, &db, &db);
	static_cast<CatModule*>(info.at(7))->frame = mlx_new_image(mlx, 199, 157);

	mlx_loop(mlx);
}

GraphicDisplay::~GraphicDisplay(){}

void GraphicDisplay::StrtoWin(int x, int y, std::string str) {
	STR(GraphicDisplay::inst->mlx, GraphicDisplay::inst->win,
		x, y, 0xffffff, const_cast<char*>(str.c_str()));
}

void GraphicDisplay::putBar(int x, int y, int ind, float f) {
	for (int i = 0; i < static_cast<int>(f); i++)	
		for (int k = 0; k < 2; k++)
			mlx_pixel_put(GraphicDisplay::inst->mlx, GraphicDisplay::inst->win,
				x + ind + k, y + 120 - i, 0xffffff);
}

void GraphicDisplay::putBarRAM(int x, int y, int ind, float f) {
	for (int k = 0; k < 3; k++)
		mlx_pixel_put(GraphicDisplay::inst->mlx, GraphicDisplay::inst->win,
			x + ind + k, y + 20, 0xffffff);
	for (int i = 0; i < static_cast<int>(f); i++)
		for (int k = 0; k < 3; k++)
			mlx_pixel_put(GraphicDisplay::inst->mlx, GraphicDisplay::inst->win,
			x + ind + k, y + 120 - i, 0xffffff);
}

void GraphicDisplay::fillBackground(int st, int h) {
	for (int x = 30; x < 270; x++)
		for (int y = st; y < st + h; y++)
			mlx_pixel_put(GraphicDisplay::inst->mlx, GraphicDisplay::inst->win,
				x, y, 0x5c707c);
}

int	refreshGraphicDisplay()
{
	for (int y = 0; y < GraphicDisplay::inst->winHeight; y++)
		for (int x = 0; x < W; x++)
			mlx_pixel_put(GraphicDisplay::inst->mlx,
				GraphicDisplay::inst->win, x, y, 0x738c9b);
	int h = 30;
	for (unsigned int i = 0; i < GraphicDisplay::inst->getInfo().size(); i++)
		if (GraphicDisplay::inst->getInfo().at(i)->onOff())
		{
			GraphicDisplay::inst->getInfo().at(i)->graphicDisplay(40, h);
			h += GraphicDisplay::inst->getInfo().at(i)->getHeight() + 20;
		}
	return 0;
}

std::vector<IMonitorModule*>	GraphicDisplay::getInfo() const{
	return (info);}
