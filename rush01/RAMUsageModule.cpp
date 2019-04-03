#include "RAMUsageModule.hpp"

RAMUsageModule::RAMUsageModule(std::string const name) : 
	on(0), _stats(), _recentStats(), _name(name), _size(2), _height(170){
	system("mkdir monitorFiles >/dev/null 2>/dev/null");
	this->update();}

RAMUsageModule::RAMUsageModule(RAMUsageModule const &other){
	*this = other;}

bool RAMUsageModule::onOff(){
	return this->on;}

void  RAMUsageModule::Switch(void) {
	this->on = !this->on;
}

RAMUsageModule::~RAMUsageModule(){}

RAMUsageModule	&RAMUsageModule::operator=(RAMUsageModule const &){
	return (*this);}

std::vector<std::string> const	&RAMUsageModule::getRecentStats(void) const{
	return (this->_recentStats);}

std::vector<std::string> const	&RAMUsageModule::getStats(void) const{
	return (this->_stats);}

std::string const	&RAMUsageModule::getName(void) const{
	return (this->_name);}

void	RAMUsageModule::update(void)
{
	system((RAMUsageModule::_getInfoSysCommand).c_str());
	this->_recentStats.clear();
	this->addFileInfoToStats(this->readStatsFile());
}

int const	&RAMUsageModule::getSize(void) const{
	return (this->_size);}

int const	&RAMUsageModule::getHeight(void) const{
	return (this->_height);}

const std::string	RAMUsageModule::readStatsFile(void) const
{
	std::ifstream file;
	file.open(RAMUsageModule::_monitorFilePath);
	std::string line = "";
	if (file.is_open())
	{
		std::getline(file, line);
		file.close();
	}
	else
		line = "PhysMem: ERROR used (ERROR wired), ERROR unused.";
	return line;
}

void	RAMUsageModule::graphicDisplay(int x, int y)
{
	static float totalRAM = 0;
	GraphicDisplay::fillBackground(y, _height);
	this->update();
	std::vector<std::string> stats
		= this->getStats();
	if (totalRAM == 0)
		totalRAM = stof(stats.at(stats.size() - 1)) + stof(stats.at(stats.size() - 2));
	GraphicDisplay::StrtoWin(x - 15, y - 12, "RAM usage:");
	for (int i = (stats.size() > 130 ? stats.size() - 130 : 0);
		i < static_cast<int>(stats.size()); i += 2)
		GraphicDisplay::putBarRAM(x + 10, y + 10,
			(stats.size() - i) / 2 * 3, 100 * stof(stats.at(i)) / totalRAM);
	GraphicDisplay::StrtoWin(x + 160, y + 140, stats.at(stats.size() - 2));
}

void	RAMUsageModule::addFileInfoToStats(std::string info)
{
	std::string token;
	size_t pos = info.find(": ") + 2;
	size_t end = info.find(" used");
	token = info.substr(pos, end - pos);
	this->_stats.push_back(token); // used
	this->_recentStats.push_back(token);

	pos = info.find(", ", end) + 2;
	end = info.find(" unused", pos);
	token = info.substr(pos, end - pos);
	this->_stats.push_back(token); // unused
	this->_recentStats.push_back(token);
	if (this->_stats.size() > 400)
	{
		this->_stats.erase(this->_stats.begin());
		this->_stats.erase(this->_stats.begin());
	}
}

const std::string RAMUsageModule::_monitorFilePath = "monitorFiles/ramUsage.monitor";
const std::string RAMUsageModule::_getInfoSysCommand = "top -l 1 | grep \"PhysMem:\" > " + RAMUsageModule::_monitorFilePath;
