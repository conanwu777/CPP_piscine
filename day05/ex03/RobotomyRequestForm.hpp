#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include "Form.hpp"

class RobotomyRequestForm : public Form {
		std::string target;
		void action(void) const;
	public:
		RobotomyRequestForm(std::string s);
		static Form* make(std::string target);
};

#endif