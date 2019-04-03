#include "TextDisplay.hpp"

TextDisplay* TextDisplay::inst;

TextDisplay::TextDisplay(std::vector<IMonitorModule*> info, std::string modes) : info(info), modes(modes)
{
	TextDisplay::inst = this;
	initscr();
	noecho();
	cbreak();
	nodelay(stdscr, TRUE);
 	curs_set(FALSE);
	raw();
	int ch;
	while (1)
	{
		ch = getch();
		if (ch != ERR)
		{
			if (ch == 'q')
			{
				endwin();
				exit(1);
			}
		}
		refreshTextDisplay();
	}
}

TextDisplay::~TextDisplay(){}

std::vector<IMonitorModule*>	TextDisplay::getInfo() const{
	return (info);}

int refreshTextDisplay()
{
	clear();
	int row, col;
	getmaxyx(stdscr, row, col);
	int x = 0;
	int y = 0;
	std::string modes = TextDisplay::inst->getModes();
	
	IMonitorModule *dtInfo = TextDisplay::inst->getDt();
	IMonitorModule *hostInfo = TextDisplay::inst->getHostname();
	IMonitorModule *cpuUsage = TextDisplay::inst->getUsage();
	IMonitorModule *memUsage = TextDisplay::inst->getRam();
	IMonitorModule *netUsage = TextDisplay::inst->getNet();
	IMonitorModule *cpuInfo = TextDisplay::inst->getCpu();
	IMonitorModule *osInfo = TextDisplay::inst->getOsinfo();
	// IMonitorModule *catInfo = TextDisplay::inst->getCatInfo();

	dtInfo->update();
	hostInfo->update();
	cpuUsage->update();
	memUsage->update();
	netUsage->update();
	cpuInfo->update();
	osInfo->update();
	// catInfo->update();

	std::vector<std::string> dtStats = dtInfo->getRecentStats();
	std::vector<std::string> hostStats = hostInfo->getRecentStats();
	std::vector<std::string> cpuStats = cpuUsage->getRecentStats();
	std::vector<std::string> memStats = memUsage->getRecentStats();
	std::vector<std::string> netStats = netUsage->getRecentStats();
	std::vector<std::string> cpuInfoStats = cpuInfo->getRecentStats();
	std::vector<std::string> osStats = osInfo->getRecentStats();
	// std::vector<std::string> catStats = catInfo->getRecentStats();

	int titleLines = 1;
	int staticsLines = (modes.find("1") != std::string::npos ? 1 : 0) + 
		(modes.find("2") != std::string::npos ? 1 : 0) + 
		(modes.find("3") != std::string::npos ? 1 : 0) + 
		(modes.find("4") != std::string::npos ? 2 : 0);
	int cpuLines = (modes.find("5") != std::string::npos ? cpuUsage->getSize() + 1 : 0);
	int ramLines = (modes.find("6") != std::string::npos ? memUsage->getSize() + 1: 0);
	int netLines = (modes.find("7") != std::string::npos ? netUsage->getSize() + 1: 0);
	// int catLines = (modes.find("8") != std::string::npos ? catInfo.getSize() : 0);

	WINDOW *titleW = derwin(stdscr, titleLines + 2, col, 0, x);
	int offset = 2;
	WINDOW *staticsW = derwin(stdscr, staticsLines + 2, col, titleLines + offset, x);
	offset += (staticsLines ? 2 : 0);
	WINDOW *cpuW = derwin(stdscr, cpuLines + 2, col, titleLines + staticsLines + offset, x);
	offset += (cpuLines ? 2 : 0);
	WINDOW *ramW = derwin(stdscr, ramLines + 2, col, titleLines + staticsLines + cpuLines + offset, x);
	offset += (ramLines ? 2 : 0);
	WINDOW *netW = derwin(stdscr, netLines + 2, col, titleLines + staticsLines + cpuLines + ramLines + offset, x);
	offset += (netLines ? 2 : 0);
	// WINDOW *catW = derwin(stdscr, netLines + 2, col, titleLines + staticsLines + cpuLines + ramLines + netLines + offset, x);

	box(titleW, '|', '=');
	mvwprintw(titleW, 1, col / 2 - 5, "ft_gkrellm");

	if (staticsLines)
	{
		y = 1;
		box(staticsW, '|', '-');
		if (modes.find("1") != std::string::npos)
		{
			mvwprintw(staticsW, y, x + 2, (dtStats[0]).c_str());
			y++;
		}
		if (modes.find("2") != std::string::npos)
		{
			mvwprintw(staticsW, y, x + 2, (hostStats[1] + "@" + hostStats[0]).c_str());
			y++;
		}
		if (modes.find("3") != std::string::npos)
		{
			mvwprintw(staticsW, y, x + 2, ("OS: " + osStats[0] + " " + osStats[1]).c_str());
			y++;
		}
		if (modes.find("4") != std::string::npos)
		{
			mvwprintw(staticsW, y, x + 2, (cpuInfoStats[0] + " " + cpuInfoStats[1] + " " + cpuInfoStats[2]).c_str());
			mvwprintw(staticsW, y + 1, x + 6, (cpuInfoStats[3] + " (" + cpuInfoStats[4] + "C/" + cpuInfoStats[5] + "T)").c_str());
		}
	}

	if (cpuLines)
	{
		y = 1;
		box(cpuW, '|', '-');
		mvwprintw(cpuW, y, x + 2, "CPU Usage:");
		mvwprintw(cpuW, y + 1, x + 4, ("User: " + cpuStats[0] + "%%").c_str());
		mvwprintw(cpuW, y + 2, x + 4, ("Sys:  " + cpuStats[1] + "%%").c_str());
		mvwprintw(cpuW, y + 3, x + 4, ("Idle: " + cpuStats[2] + "%%").c_str());
	}
		

	if (ramLines)
	{
		y = 1;
		box(ramW, '|', '-');
		mvwprintw(ramW, y, x + 2, "Memory Usage:");
		mvwprintw(ramW, y + 1, x + 4, ("Used: " + memStats[0]).c_str());
		mvwprintw(ramW, y + 2, x + 4, ("Free: " + memStats[1]).c_str());
	}

	if (netLines)
	{
		y = 1;
		box(netW, '|', '-');
		mvwprintw(netW, y, x + 2, "Network Usage:");
		mvwprintw(netW, y + 1, x + 4, ("In:  " + netStats[0] + " packets").c_str());
		mvwprintw(netW, y + 2, x + 4, ("     " + netStats[1]).c_str());
		mvwprintw(netW, y + 3, x + 4, ("Out: " + netStats[2] + " packets").c_str());
		mvwprintw(netW, y + 4, x + 4, ("     " + netStats[3]).c_str());
	}

	// if (catLines) // assumes the cat has 5 lines of graphics
	// {
	// 	y = 1;
	// 	box(catW, '|', '-');
	// 	mvwprintw(catW, y, x + 2, catStats[0].c_str());
	// 	mvwprintw(catW, y + 1, x + 2, catStats[1].c_str());
	// 	mvwprintw(catW, y + 2, x + 2, catStats[2].c_str());
	// 	mvwprintw(catW, y + 3, x + 2, catStats[3].c_str());
	// 	mvwprintw(catW, y + 4, x + 2, catStats[4].c_str());
	// }
	refresh();
	return (0);
}

std::string TextDisplay::getModes(void)
{
	return this->modes;
}

IMonitorModule*	TextDisplay::getHostname() const
{
	return (info.at(0));
}

IMonitorModule*	TextDisplay::getOsinfo() const
{
	return (info.at(1));
}

IMonitorModule*	TextDisplay::getDt() const
{
	return (info.at(2));
}

IMonitorModule*	TextDisplay::getCpu() const
{
	return (info.at(3));
}

IMonitorModule*	TextDisplay::getUsage() const
{
	return (info.at(4));
}

IMonitorModule*	TextDisplay::getRam() const
{
	return (info.at(5));
}

IMonitorModule*	TextDisplay::getNet() const
{
	return (info.at(6));
}
