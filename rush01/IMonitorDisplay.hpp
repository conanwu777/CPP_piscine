#ifndef IMonitorDisplay_HPP
# define IMonitorDisplay_HPP
# include "IMonitorModule.hpp"

class IMonitorDisplay {
		virtual std::vector<IMonitorModule*>	getInfo() const = 0;
};

#endif
