#include "HostnameModule.hpp"

HostnameModule::HostnameModule(std::string const name) :
	on(0), _stats(), _recentStats(), _name(name), _size(2), _height(70)
{
	char hn[256];
	char un[256];
	hn[255] = '\0';
	un[255] = '\0';
	gethostname(hn, 255);
	getlogin_r(un, 255);
	this->_stats.push_back(hn);
	this->_stats.push_back(un);
	return ;
}

bool HostnameModule::onOff(){
	return this->on;}

void HostnameModule::Switch(void) {
	this->on = !this->on;
}

HostnameModule::HostnameModule(HostnameModule const &other){
	*this = other;
	return;}

HostnameModule::~HostnameModule(){}

HostnameModule	&HostnameModule::operator=(HostnameModule const &){
	return (*this);}

std::vector<std::string> const	&HostnameModule::getRecentStats(void) const{
	return (this->_stats);}

std::vector<std::string> const	&HostnameModule::getStats(void) const{
	return (this->_stats);}

void	HostnameModule::graphicDisplay(int x, int y)
{
	GraphicDisplay::fillBackground(y, _height);
	std::vector<std::string> stats
		= this->getStats();
	GraphicDisplay::StrtoWin(x - 15, y - 12, "Hostname:");
	for (unsigned int i = 0; i < stats.size(); i++)
		GraphicDisplay::StrtoWin(x, y + 20 * (i + 1), stats.at(i));
}

std::string const	&HostnameModule::getName(void) const{
	return (this->_name);}

void	HostnameModule::update(void) {}

int const	&HostnameModule::getSize(void) const{
	return (this->_size);}

int const	&HostnameModule::getHeight(void) const{
	return (this->_height);}
