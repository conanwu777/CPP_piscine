#include "CPUInfoModule.hpp"

CPUInfoModule::CPUInfoModule(std::string const name) :
	on(0), _stats(), _recentStats(), _name(name), _size(6), _height(160)
{
	char buffer[256];
	buffer[255] = '\0';
	int cores;
	int threads;
	size_t size = 255;
	sysctlbyname("machdep.cpu.brand_string", &buffer, &size, NULL, 0);
	sysctlbyname("machdep.cpu.core_count", &cores, &size, NULL, 0);
	sysctlbyname("machdep.cpu.thread_count", &threads, &size, NULL, 0);
	std::string info = buffer;
	int i = 0;
	size_t pos = 0;
	std::string delimiter = " ";
	std::string token;
	while ((pos = info.find(delimiter)) != std::string::npos) {
	    token = info.substr(0, pos);
	    if (token.compare("@") != 0 && token.compare("CPU") != 0)
	    {
	    	this->_stats.push_back(token);
			i++;
		}
	    info.erase(0, pos + delimiter.length());
	}
	this->_stats.push_back(info); //speed
	this->_stats.push_back(std::to_string(cores)); // cores
	this->_stats.push_back(std::to_string(threads)); // threads
	i += 3;
	this->_size = i;
	return ;
}

CPUInfoModule::~CPUInfoModule(){}

bool CPUInfoModule::onOff(){
	return this->on;}

void CPUInfoModule::Switch(void) {
	this->on = !this->on;
}

CPUInfoModule::CPUInfoModule(CPUInfoModule const &other){
	*this = other;}

CPUInfoModule	&CPUInfoModule::operator=(CPUInfoModule const &){
	return (*this);}

void	CPUInfoModule::graphicDisplay(int x, int y){
	GraphicDisplay::fillBackground(y, _height);
	std::vector<std::string> stats
		= this->getStats();
	GraphicDisplay::StrtoWin(x - 15, y - 12, "CPU info:");
	GraphicDisplay::StrtoWin(x, y + 20 , "Mfr:");
	GraphicDisplay::StrtoWin(x + 100, y + 20 , stats.at(0));
	GraphicDisplay::StrtoWin(x, y + 40 , "Brand:");
	GraphicDisplay::StrtoWin(x + 100, y + 40 , stats.at(1));
	GraphicDisplay::StrtoWin(x, y + 60 , "Model:");
	GraphicDisplay::StrtoWin(x + 100, y + 60 , stats.at(2));
	GraphicDisplay::StrtoWin(x, y + 80 , "Speed:");
	GraphicDisplay::StrtoWin(x + 100, y + 80 , stats.at(3));
	GraphicDisplay::StrtoWin(x, y + 100 , "Cores:");
	GraphicDisplay::StrtoWin(x + 100, y + 100 , stats.at(4));
	GraphicDisplay::StrtoWin(x, y + 120 , "Threads:");
	GraphicDisplay::StrtoWin(x + 100, y + 120 , stats.at(5));
}

std::vector<std::string> const	&CPUInfoModule::getRecentStats(void) const{
	return (this->_stats);}

std::vector<std::string> const	&CPUInfoModule::getStats(void) const{
	return (this->_stats);}

std::string const	&CPUInfoModule::getName(void) const{
	return (this->_name);}

void	CPUInfoModule::update(void){}

int const	&CPUInfoModule::getSize(void) const{
	return (this->_size);}

int const	&CPUInfoModule::getHeight(void) const{
	return (this->_height);}
