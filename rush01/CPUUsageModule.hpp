#ifndef CPUUSAGEMODULE_H
# define CPUUSAGEMODULE_H

#include "IMonitorModule.hpp"
#include "GraphicDisplay.hpp"
#include <algorithm>
#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

class CPUUsageModule : public IMonitorModule
{
public:
	CPUUsageModule(void);
	CPUUsageModule(CPUUsageModule const &other);
	CPUUsageModule	&operator=(CPUUsageModule const &other);
	CPUUsageModule(std::string const name);
	virtual ~CPUUsageModule(void);

	void							graphicDisplay(int x, int y);
	void							update(void);
	const std::string				readStatsFile(void) const;
	void							addFileInfoToStats(std::string const info);
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
	static const std::string		_monitorFilePath;
	static const std::string		_getInfoSysCommand;
};

#endif
