#ifndef HOSTNAMEMODULE_H
# define HOSTNAMEMODULE_H

#include "IMonitorModule.hpp"
#include "GraphicDisplay.hpp"
#include <unistd.h>
#include <vector>
#include <iostream>
#include <string>

class HostnameModule : public IMonitorModule
{
	HostnameModule(void);
	HostnameModule(HostnameModule const &other);
	HostnameModule	&operator=(HostnameModule const &other);
public:
	HostnameModule(std::string const name);
	virtual ~HostnameModule(void);
	
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
