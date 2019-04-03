#ifndef IMONITORMODULE_HPP
# define IMONITORMODULE_HPP
#include <vector>
#include <string>

class IMonitorModule
{
	public:
		virtual bool							onOff(void) = 0;
		virtual void							Switch(void) = 0;
		virtual void							update(void) = 0;
		virtual std::vector<std::string> const	&getRecentStats(void) const = 0;
		virtual std::vector<std::string> const	&getStats(void) const = 0;
		virtual std::string const				&getName(void) const = 0;
		virtual int const						&getSize(void) const = 0;
		virtual int const						&getHeight(void) const = 0;
		virtual void							graphicDisplay(int x, int y) = 0;
};

#endif
