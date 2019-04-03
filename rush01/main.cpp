#include "GraphicDisplay.hpp"
#include "TextDisplay.hpp"

int main(int argc, char **argv)
{
	std::string textFlag = "-t";
	std::string modeFlag = "-m";
	bool textMode = false;
	std::string modes = "1 2 3 4 5 6 7 8";
	for (int i = 1; i < argc; i++)
	{
		if (textFlag.compare(argv[i]) == 0)
			textMode = true;
		else if (modeFlag.compare(argv[i]) == 0)
		{
			modes = "";
			for (int j = i + 1; j < argc; j++)
				modes += std::string(argv[j]) + " ";
			break;
		}
		else
		{
			std::cout << "usage: ./ft_gkrellm [-t] [-m [module numbers]]" << std::endl;
			std::cout << "\t-t: optional. Activates TEXT mode" << std::endl;
			std::cout << "\t-m: optional. Space-separated list of integers that selects individual modules to show. This should be the last parameter passed in" << std::endl;
			std::cout << "\t\tModule numbers:" << std::endl;
			std::cout << "\t\t1: DateTime" << std::endl;
			std::cout << "\t\t2: Hostname" << std::endl;
			std::cout << "\t\t3: OS Info" << std::endl;
			std::cout << "\t\t4: CPU Info" << std::endl;
			std::cout << "\t\t5: CPU Usage" << std::endl;
			std::cout << "\t\t6: RAM Usage" << std::endl;
			std::cout << "\t\t7: Network" << std::endl;
			std::cout << "\t\t8: Cat" << std::endl;
			return (0);
		}
	}
	std::string name = "info";
	HostnameModule hostname(name);
	OSInfoModule osinfo(name);
	DateTimeModule dt(name);
	CPUInfoModule cpu(name);
	CPUUsageModule usage(name);
	RAMUsageModule ram(name);
	NetworkUsageModule net(name);
	CatModule cat(name);

	std::vector<IMonitorModule*> info;
	info.push_back(&hostname);
	info.push_back(&osinfo);
	info.push_back(&dt);
	info.push_back(&cpu);
	info.push_back(&usage);
	info.push_back(&ram);
	info.push_back(&net);
	info.push_back(&cat);

	if (modes.find('1') != std::string::npos)
		dt.on = 1;
	if (modes.find('2') != std::string::npos)
		hostname.on = 1;
	if (modes.find('3') != std::string::npos)
		osinfo.on = 1;
	if (modes.find('4') != std::string::npos)
		cpu.on = 1;
	if (modes.find('5') != std::string::npos)
		usage.on = 1;
	if (modes.find('6') != std::string::npos)
		ram.on = 1;
	if (modes.find('7') != std::string::npos)
		net.on = 1;
	if (modes.find('8') != std::string::npos)
		cat.on = 1;

	if (textMode)
		TextDisplay t(info, modes);
	else
		GraphicDisplay g(info);
	return (0);
}
