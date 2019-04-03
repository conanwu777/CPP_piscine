#ifndef LOGGER_HPP
#define LOGGER_HPP
#include <iostream>
#include <fstream>

class Logger {
	std::ofstream _ofs;
	void logToConsole(std::string str);
	void logToFile(std::string str);
	std::string makeLogEntry(std::string const & message);
public:
	Logger(std::string file);
	~Logger(void);
	void log(std::string const & dest, std::string const & message);
};

#endif