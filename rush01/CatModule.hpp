#ifndef CATMODULE_H
# define CATMODULE_H

#include "IMonitorModule.hpp"
#include "GraphicDisplay.hpp"
#include <ctime>
#include <vector>
#include <iostream>
#include <sstream>
#include <string>

class CatModule : public IMonitorModule
{
	CatModule(void);
	CatModule(CatModule const &other);
	CatModule	&operator=(CatModule const &other);
public:
	CatModule(std::string const name);
	virtual ~CatModule(void);
	
	void							graphicDisplay(int x, int y);
	void							update(void);
	std::vector<std::string> const	&getRecentStats(void) const;
	std::vector<std::string> const	&getStats(void) const;
	std::string const				&getName(void) const;
	int const						&getSize(void) const;
	int const						&getHeight(void) const;
	bool							onOff(void);
	void							Switch(void);
	bool							on;
	char*							cat;
	void*							frame;

private:
	std::vector<std::string>		_stats;
	std::vector<std::string>		_recentStats;
	std::string						_name;
	int								_size;
	int								_height;
};

std::string resize(std::string str);

#endif
