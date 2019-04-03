#ifndef CentralBureaucracy_HPP
# define CentralBureaucracy_HPP
# include "Bureaucrat.hpp"
# include "OfficeBlock.hpp"
# include <iostream>

class CentralBureaucracy {
		OfficeBlock	obs[20];
		std::string targets;
		CentralBureaucracy(CentralBureaucracy const & src);
		CentralBureaucracy & operator=(const CentralBureaucracy & rhs);
	public:
		CentralBureaucracy();
		~CentralBureaucracy();

		void addBureaucrat(Bureaucrat* b);
		void queueUp(std::string target);
		std::string getNextTarget(void);
		void doBureaucracy();
};

#endif
