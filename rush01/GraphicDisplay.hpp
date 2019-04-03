#ifndef GRAPHICDISPLAY_HPP
# define GRAPHICDISPLAY_HPP

#include <vector>
#include <string>
#include "IMonitorDisplay.hpp"
#include "OSInfoModule.hpp"
#include "HostnameModule.hpp"
#include "DateTimeModule.hpp"
#include "CPUUsageModule.hpp"
#include "CPUInfoModule.hpp"
#include "RAMUsageModule.hpp"
#include "NetworkUsageModule.hpp"
#include "CatModule.hpp"

class OSInfoModule;

class GraphicDisplay : public IMonitorDisplay
{
	private:
		GraphicDisplay(GraphicDisplay const &other);
		GraphicDisplay	&operator=(GraphicDisplay const &other);
		GraphicDisplay();
		std::vector<IMonitorModule*> info;
		std::string modes;
	public:
		GraphicDisplay(std::vector<IMonitorModule*> info);
		virtual ~GraphicDisplay(void);
		
		static void StrtoWin(int x, int y, std::string str);
		static void putBar(int x, int y, int ind, float f);
		static void putBarRAM(int x, int y, int ind, float f);
		static void fillBackground(int st, int h);

		void	*mlx;
		void	*win;
		int 	winHeight;
		std::vector<IMonitorModule*>	getInfo() const;	
		static GraphicDisplay* inst;
};

int	k_control(int key);
int refreshGraphicDisplay(void);

#endif
