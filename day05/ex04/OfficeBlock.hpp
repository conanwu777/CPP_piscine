#ifndef OFFICEBLOCK_HPP
# define OFFICEBLOCK_HPP
# include "Intern.hpp"
# include "Bureaucrat.hpp"
# include <iostream>
# include <stdexcept>

class OfficeBlock {
		Intern*		intern;
		Bureaucrat*	sign;
		Bureaucrat*	exc;
		OfficeBlock & operator=(const OfficeBlock & rhs);
		OfficeBlock(OfficeBlock const & src);
	public:
		OfficeBlock();
		~OfficeBlock();
		OfficeBlock(Intern*, Bureaucrat*, Bureaucrat*);

		void setIntern(Intern &);
		void setSigner(Bureaucrat &);
		void setExecutor(Bureaucrat &);
		void doBureaucracy(std::string name, std::string target);

		class NoInternException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class NoSignerException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class NoExcException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class SignerException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class ExcException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif
