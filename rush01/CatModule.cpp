#include "CatModule.hpp"

extern "C"
{
# include "mlx.h"
}

CatModule::CatModule(std::string const name) :
	on(0), _stats(), _recentStats(), _name(name), _size(0), _height(160){
		cat = NULL;
		frame = NULL;
}

bool CatModule::onOff(){
	return this->on;}

void CatModule::Switch(void) {
	this->on = !this->on;
}

CatModule::~CatModule(){
	mlx_destroy_image(GraphicDisplay::inst->mlx, frame);
}

std::vector<std::string> const	&CatModule::getRecentStats(void) const{
	return _stats;
}

std::vector<std::string> const	&CatModule::getStats(void) const{
	return _recentStats;
}

std::string const	&CatModule::getName(void) const{
	return (this->_name);}

void	CatModule::graphicDisplay(int, int y)
{
	int		db;
	static int count = 0;
	char* str = mlx_get_data_addr(frame, &db, &db, &db);
	for (int i = 0; i < 199 * 157; i++)
		reinterpret_cast<unsigned int*>(str)[i] =
		reinterpret_cast<unsigned int*>(cat)[i + count * 199 * 157];
	mlx_put_image_to_window(GraphicDisplay::inst->mlx,
		GraphicDisplay::inst->win, frame, 50, y);
	if (count < 16)
		count++;
	else
		count = 0;
}

void	CatModule::update(void){}

int const	&CatModule::getSize(void) const{
	return (this->_size);}

int const	&CatModule::getHeight(void) const{
	return (this->_height);}
