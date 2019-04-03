#include "DateTimeModule.hpp"

DateTimeModule::DateTimeModule(std::string const name) :
	on(0), _stats(), _recentStats(), _name(name), _size(1), _height(50){
	this->update();}

bool DateTimeModule::onOff(){
	return this->on;}

void DateTimeModule::Switch(void) {
	this->on = !this->on;
}

DateTimeModule::DateTimeModule(DateTimeModule const &other){
	*this = other;}

DateTimeModule::~DateTimeModule(){}

DateTimeModule	&DateTimeModule::operator=(DateTimeModule const &){
	return (*this);}

std::vector<std::string> const	&DateTimeModule::getRecentStats(void) const{
	return (this->_stats);}

std::vector<std::string> const	&DateTimeModule::getStats(void) const{
	return (this->_stats);}

std::string const	&DateTimeModule::getName(void) const{
	return (this->_name);}

std::string resize(std::string str){
	if (str.size() < 2)
	{
		str = "0" + str;
		str.resize(2);
	}
	return (str);
}

void	DateTimeModule::graphicDisplay(int x, int y)
{
	GraphicDisplay::fillBackground(y, _height);
	this->update();
	std::vector<std::string> stats
		= this->getStats();
	GraphicDisplay::StrtoWin(x - 15, y - 12, "Date/Time:");
	GraphicDisplay::StrtoWin(x, y + 20, stats.at(stats.size() - 1));
}

void	DateTimeModule::update(void)
{
	time_t rawtime;
	struct tm *ts;
	std::string	month[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
	std::string	week[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
	rawtime = time(&rawtime);
	ts = localtime(&rawtime);
	std::stringstream ss;
	std::string mon = month[ts->tm_mon];
	std::string wk = week[ts->tm_wday];
	std::string hour = resize(std::to_string(ts->tm_hour));
	std::string min = resize(std::to_string(ts->tm_min));
	std::string sec = resize(std::to_string(ts->tm_sec));
	ss << wk << " " << mon << " " << ts->tm_year + 1900
		<< " " << hour << ":" << min << ":" << sec;
	this->_stats.push_back(ss.str());
	if (this->_stats.size() > 10)
		this->_stats.erase(this->_stats.begin());
}

int const	&DateTimeModule::getSize(void) const{
	return (this->_size);}

int const	&DateTimeModule::getHeight(void) const{
	return (this->_height);}
