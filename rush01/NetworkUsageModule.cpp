#include "NetworkUsageModule.hpp"

NetworkUsageModule::NetworkUsageModule(std::string const name) : 
	on(0), _stats(), _recentStats(), _name(name), _size(4), _height(120)
{
	system("mkdir monitorFiles >/dev/null 2>/dev/null");
	this->update();
}

bool NetworkUsageModule::onOff(){
	return this->on;}

void NetworkUsageModule::Switch(void) {
	this->on = !this->on;
}

NetworkUsageModule::~NetworkUsageModule(){}

NetworkUsageModule::NetworkUsageModule(NetworkUsageModule const &other){
	*this = other;}

NetworkUsageModule	&NetworkUsageModule::operator=(NetworkUsageModule const &){
	return (*this);}

std::vector<std::string> const	&NetworkUsageModule::getRecentStats(void) const
{
	return (this->_recentStats);
}

std::vector<std::string> const	&NetworkUsageModule::getStats(void) const{
	return (this->_stats);}

std::string const	&NetworkUsageModule::getName(void) const{
	return (this->_name);}

void	NetworkUsageModule::update(void)
{
	system((NetworkUsageModule::_getInfoSysCommand).c_str());
	this->_recentStats.clear();
	this->addFileInfoToStats(this->readStatsFile());
}

int const	&NetworkUsageModule::getSize(void) const{
	return (this->_size);}

int const	&NetworkUsageModule::getHeight(void) const{
	return (this->_height);}

const std::string	NetworkUsageModule::readStatsFile(void) const
{
	std::ifstream file;
	file.open(NetworkUsageModule::_monitorFilePath);
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

void	NetworkUsageModule::graphicDisplay(int x, int y)
{
	GraphicDisplay::fillBackground(y, _height);
	this->update();
	std::vector<std::string> stats
		= this->getStats();
	GraphicDisplay::StrtoWin(x - 15, y - 12, "Network Usage:");
	GraphicDisplay::StrtoWin(x, y + 20, "Pks In:");
	GraphicDisplay::StrtoWin(x + 100, y + 20, stats.at(stats.size() - 4));
	GraphicDisplay::StrtoWin(x, y + 40, "In Size:");
	GraphicDisplay::StrtoWin(x + 100, y + 40, stats.at(stats.size() - 3));
	GraphicDisplay::StrtoWin(x, y + 60, "Pks Out:");
	GraphicDisplay::StrtoWin(x + 100, y + 60, stats.at(stats.size() - 2));
	GraphicDisplay::StrtoWin(x, y + 80, "Out size:");
	GraphicDisplay::StrtoWin(x + 100, y + 80, stats.at(stats.size() - 1));
}

void	NetworkUsageModule::addFileInfoToStats(std::string const info)
{
	std::string token;
	size_t pos = info.find("packets: ") + 9;
	size_t end = info.find("/") - 1;
	token = info.substr(pos, end - pos);
	this->_stats.push_back(token); // packets in
	this->_recentStats.push_back(token);

	pos = info.find("/", end) + 1;
	end = info.find(" in", pos);
	token = info.substr(pos, end - pos);
	this->_stats.push_back(token); // in size
	this->_recentStats.push_back(token);

	pos = info.find(", ", end) + 2;
	end = info.find("/", pos) - 1;
	token = info.substr(pos, end - pos);
	this->_stats.push_back(token); // packets out
	this->_recentStats.push_back(token);

	pos = info.find("/", end) + 1;
	end = info.find(" out", pos);
	token = info.substr(pos, end - pos);
	this->_stats.push_back(token); // out size
	this->_recentStats.push_back(token);

	if (this->_stats.size() > 20)
	{
		this->_stats.erase(this->_stats.begin());
		this->_stats.erase(this->_stats.begin());
		this->_stats.erase(this->_stats.begin());
		this->_stats.erase(this->_stats.begin());
	}
}

const std::string NetworkUsageModule::_monitorFilePath = "monitorFiles/netUsage.monitor";
const std::string NetworkUsageModule::_getInfoSysCommand = "top -l 1 | grep \"Networks:\" > " + NetworkUsageModule::_monitorFilePath;
