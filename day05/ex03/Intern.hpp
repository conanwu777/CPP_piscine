#ifndef INTERN_HPP
# define INTERN_HPP
# include "Form.hpp"
# include <iostream>
# include <stdexcept>

class Form;

class Intern {
	public:
		Intern();
		Intern & operator=(const Intern & rhs);
		Intern(Intern const & src);
		~Intern();

		Form* makeForm(const std::string name, const std::string target) const;

};

#endif
