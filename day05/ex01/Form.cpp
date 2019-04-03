#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(Form const & src) : name(src.getName()), sign(src.getSign()),
gradeSign(src.getGradeSign()), gradeEx(src.getGradeEx()) {}

Form::~Form(){}

Form::Form(std::string n, int gs, int ge) :
name(n), sign(0), gradeSign(gs), gradeEx(ge){
	if (gs < 1 || ge < 1)
		throw GradeTooHighException();
	else if (gs > 150 || ge > 150)
		throw GradeTooLowException();
}

Form & Form::operator=(const Form & rhs) {
	this->sign = rhs.sign;
	return *this;}

std::string Form::getName() const {
	return this->name;}

bool Form::getSign() const {
	return this->sign;}

int Form::getGradeSign() const {
	return this->gradeSign;}

int Form::getGradeEx() const {
	return this->gradeEx;}

void Form::beSigned(const Bureaucrat & b) {
	if (b.getGrade() > this->gradeSign)
		throw GradeTooLowException();
	this->sign = 1;
}

const char* Form::GradeTooHighException::what() const throw() {
		return ("Form Grade is too HIGH");}

const char* Form::GradeTooLowException::what() const throw() {
		return ("Form Grade is too LOW");}

std::ostream & operator<<(std::ostream & ofs, const Form & s) {
	ofs << s.getName() << " signed " << s.getSign() << ", requires grade "
	<< s.getGradeSign() << " to sign, and grade "
	<< s.getGradeEx() << " to excute\n";
	return (ofs);
}
