#ifndef CPUINFOMODULE_H
# define CPUINFOMODULE_H

#include "IMonitorModule.hpp"
#include "GraphicDisplay.hpp"
#include <sys/sysctl.h>
#include <vector>
#include <iostream>
#include <sstream>
#include <string>

class CPUInfoModule : public IMonitorModule
{
public:
	CPUInfoModule(void);
	CPUInfoModule(CPUInfoModule const &other);
	CPUInfoModule	&operator=(CPUInfoModule const &other);
	CPUInfoModule(std::string const name);
	virtual ~CPUInfoModule(void);
	
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
	
private:
	std::vector<std::string>		_stats;
	std::vector<std::string>		_recentStats;
	std::string						_name;
	int								_size;
	int								_height;
};

#endif
