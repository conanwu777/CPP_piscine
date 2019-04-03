#include "Logger.hpp"
#include <ctime>

Logger::Logger(std::string file) {
	this->_ofs.open(file, std::ios::app);
}

Logger::~Logger(void) {
	_ofs.close();
}

void Logger::logToConsole(std::string str) {
	std::cout << str << std::endl;
}

void Logger::logToFile(std::string str) {
	this->_ofs << str << std::endl;
}

std::string Logger::makeLogEntry(std::string const & message) {
	std::string new_str;
	time_t t;

	time(&t);
	new_str += asctime(localtime(&t));
	new_str[24] = ' ';
	new_str += "   ";
	new_str += message;
	return (new_str);
}

void Logger::log(std::string const & dest, std::string const & message) {
	void (Logger::*f[2])(std::string str);
	std::string where[2];
	std::string str;
	int i;

	where[0] = "logToConsole";
	where[1] = "logToFile";
	f[0] = &Logger::logToConsole;
	f[1] = &Logger::logToFile;
	for (i = 0; i < 2; i++)
	{
		if (where[i].compare(dest) == 0)
			break ;
	}
	if (i == 2)
		return ;
	str = Logger::makeLogEntry(message);
	(this->*f[i])(str);

}
