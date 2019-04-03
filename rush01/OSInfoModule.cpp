#include "OSInfoModule.hpp"

OSInfoModule::OSInfoModule(std::string const name) :
	on(0), _stats(), _recentStats(), _name(name), _size(2), _height(70)
{
    struct utsname uts;
    uname(&uts);

	this->_stats.push_back(uts.sysname);
	this->_stats.push_back(uts.release);
}

bool OSInfoModule::onOff(){
	return this->on;
}

void  OSInfoModule::Switch(void) {
	this->on = !this->on;
}

OSInfoModule::~OSInfoModule(){}

OSInfoModule::OSInfoModule(OSInfoModule const &other){
	*this = other;}

OSInfoModule	&OSInfoModule::operator=(OSInfoModule const &){
	return (*this);}

std::vector<std::string> const	&OSInfoModule::getRecentStats(void) const{
	return (this->_stats);}

std::vector<std::string> const	&OSInfoModule::getStats(void) const{
	return (this->_stats);}

void	OSInfoModule::graphicDisplay(int x, int y)
{
	GraphicDisplay::fillBackground(y, _height);
	std::vector<std::string> stats
		= this->getStats();
	GraphicDisplay::StrtoWin(x - 15, y - 12, "OS info:");
	GraphicDisplay::StrtoWin(x, y + 20, "OS:");
	GraphicDisplay::StrtoWin(x + 100, y + 20, stats.at(0));
	GraphicDisplay::StrtoWin(x, y + 40, "Version:");
	GraphicDisplay::StrtoWin(x + 100, y + 40, stats.at(1));
}

std::string const	&OSInfoModule::getName(void) const{
	return (this->_name);}

void	OSInfoModule::update(void){}

int const	&OSInfoModule::getSize(void) const{
	return (this->_size);}

int const	&OSInfoModule::getHeight(void) const {
	return (this->_height);}
