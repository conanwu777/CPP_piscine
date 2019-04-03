#include "CPUUsageModule.hpp"

CPUUsageModule::CPUUsageModule(std::string const name) : 
	on(0), _stats(), _recentStats(), _name(name), _size(3), _height(390)
{
	system("mkdir monitorFiles >/dev/null 2>/dev/null");
	this->update();
}

bool CPUUsageModule::onOff(){
	return this->on;}

void CPUUsageModule::Switch(void) {
	this->on = !this->on;
}

CPUUsageModule::~CPUUsageModule(){}

CPUUsageModule::CPUUsageModule(CPUUsageModule const &other){
	*this = other;}

CPUUsageModule	&CPUUsageModule::operator=(CPUUsageModule const &){
	return (*this);}

std::vector<std::string> const	&CPUUsageModule::getRecentStats(void) const{
	return (this->_recentStats);}

std::vector<std::string> const	&CPUUsageModule::getStats(void) const{
	return (this->_stats);}

std::string const	&CPUUsageModule::getName(void) const{
	return (this->_name);}

void	CPUUsageModule::update(void){
	system((CPUUsageModule::_getInfoSysCommand).c_str());
	this->_recentStats.clear();
	this->addFileInfoToStats(this->readStatsFile());
}

int const	&CPUUsageModule::getSize(void) const{
	return (this->_size);}

int const	&CPUUsageModule::getHeight(void) const{
	return (this->_height);}

void	CPUUsageModule::graphicDisplay(int x, int y) {
	this->update();
	std::vector<std::string> stats
		= this->getStats();
	GraphicDisplay::fillBackground(y, _height);
	GraphicDisplay::StrtoWin(x - 15, y - 12, "CPU usage:");
	for (int i = (stats.size() > 201 ? stats.size() - 201 : 0); i < static_cast<int>(stats.size()); i += 3)
		GraphicDisplay::putBar(x + 5, y - 20, stats.size() - i, stof(stats.at(i)));
	GraphicDisplay::StrtoWin(x + 5, y + 100, "User:        %");
	GraphicDisplay::StrtoWin(x + 75, y + 100, stats.at(stats.size() - 3));

	for (int i = (stats.size() > 200 ? stats.size() - 200 : 1); i < static_cast<int>(stats.size()); i += 3)
		GraphicDisplay::putBar(x + 5, y + 100, stats.size() - i, stof(stats.at(i)));
	GraphicDisplay::StrtoWin(x + 5, y + 220, "System:      %");
	GraphicDisplay::StrtoWin(x + 75, y + 220, stats.at(stats.size() - 2));

	for (int i = (stats.size() > 200 ? stats.size() - 200 : 1); i < static_cast<int>(stats.size()); i += 3)
		GraphicDisplay::putBar(x + 5, y + 240, stats.size() - i, stof(stats.at(i)) + stof(stats.at(i - 1)));
	GraphicDisplay::StrtoWin(x + 5, y + 360, "Total:       %");
	std::stringstream oss;
	oss << stof(stats.at(stats.size() - 2)) + stof(stats.at(stats.size() - 3));
	GraphicDisplay::StrtoWin(x + 75, y + 360, oss.str());
}

const std::string	CPUUsageModule::readStatsFile(void) const
{
	std::ifstream file;
	file.open(CPUUsageModule::_monitorFilePath);
	std::string line = "";
	if (file.is_open())
	{
		std::getline(file, line);
		file.close();
	}
	else
		line = "User: ERROR | Sys: ERROR | Idle: ERROR";
	return line;
}

void	CPUUsageModule::addFileInfoToStats(std::string const info)
{
	std::string token;
	size_t pos = info.find(": ") + 2;
	size_t end = info.find("% user");
	token = info.substr(pos, end - pos);
	this->_stats.push_back(token); // user
	this->_recentStats.push_back(token);

	pos = info.find(", ", end) + 2;
	end = info.find("% sys", pos);
	token = info.substr(pos, end - pos);
	this->_stats.push_back(token); // sys
	this->_recentStats.push_back(token);

	pos = info.find(", ", end) + 2;
	end = info.find("% idle", pos);
	token = info.substr(pos, end - pos);
	this->_stats.push_back(token); // idle
	this->_recentStats.push_back(token);

	if (this->_stats.size() > 500)
	{
		this->_stats.erase(this->_stats.begin());
		this->_stats.erase(this->_stats.begin());
		this->_stats.erase(this->_stats.begin());
	}	
}

const std::string CPUUsageModule::_monitorFilePath = "monitorFiles/cpuUsage.monitor";
const std::string CPUUsageModule::_getInfoSysCommand
= "top -l 1 | grep \"CPU usage:\" > " + CPUUsageModule::_monitorFilePath;
