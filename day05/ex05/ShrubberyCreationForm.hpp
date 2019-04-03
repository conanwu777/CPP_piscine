#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include "Form.hpp"

class ShrubberyCreationForm : public Form {
		std::string target;
		void action(void) const;
	public:
		ShrubberyCreationForm(std::string s);
};

#endif