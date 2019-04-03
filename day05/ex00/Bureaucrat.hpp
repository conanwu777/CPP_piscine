#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include <stdexcept>

class Bureaucrat {
		const std::string name;
		int grade;
		Bureaucrat();
	public:
		Bureaucrat & operator=(const Bureaucrat & rhs);
		Bureaucrat(Bureaucrat const & src);
		~Bureaucrat();
		Bureaucrat(std::string, int);
		std::string getName() const;
		int getGrade() const;
		void incGrade();
		void decGrade();

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream & operator<<(std::ostream & ofs, const Bureaucrat & s);

#endif
