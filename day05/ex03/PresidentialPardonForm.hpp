#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include "Form.hpp"

class PresidentialPardonForm : public Form {
		std::string target;
		void action(void) const;
	public:
		PresidentialPardonForm(std::string s);
		static Form* make(std::string target);
};

#endif