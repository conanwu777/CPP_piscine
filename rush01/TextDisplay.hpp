#ifndef TEXTDISPLAY_HPP
# define TEXTDISPLAY_HPP

#include <vector>
#include <string>
#include <iostream>
#include <ncurses.h>
#include "IMonitorDisplay.hpp"
#include "OSInfoModule.hpp"
#include "HostnameModule.hpp"
#include "DateTimeModule.hpp"
#include "CPUUsageModule.hpp"
#include "CPUInfoModule.hpp"
#include "RAMUsageModule.hpp"
#include "NetworkUsageModule.hpp"

class OSInfoModule;

class TextDisplay : public IMonitorDisplay
{
	private:
		TextDisplay(TextDisplay const &other);
		TextDisplay	&operator=(TextDisplay const &other);
		TextDisplay();
		std::vector<IMonitorModule*> info;
		std::string modes;
	public:
		TextDisplay(std::vector<IMonitorModule*> info, std::string modes);
		virtual ~TextDisplay(void);

		std::vector<IMonitorModule*>	getInfo() const;
		IMonitorModule*	getHostname() const;
		IMonitorModule*	getOsinfo() const;
		IMonitorModule*	getDt() const;
		IMonitorModule*	getCpu() const;
		IMonitorModule*	getUsage() const;
		IMonitorModule*	getRam() const;
		IMonitorModule*	getNet() const;
		std::string		getModes();
		static TextDisplay* inst;
};

int refreshTextDisplay(void);

#endif
