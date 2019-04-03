#ifndef OSINFOMODULE_H
# define OSINFOMODULE_H

#include "IMonitorModule.hpp"
#include "GraphicDisplay.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <sys/utsname.h>

class OSInfoModule : public IMonitorModule
{
public:
	OSInfoModule(void);
	OSInfoModule(OSInfoModule const &other);
	OSInfoModule	&operator=(OSInfoModule const &other);
	OSInfoModule(std::string const name);
	virtual ~OSInfoModule(void);

	void							graphicDisplay(int x, int y);
	void							update(void);
	std::vector<std::string> const	&getStats(void) const;
	std::vector<std::string> const	&getRecentStats(void) const;
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
