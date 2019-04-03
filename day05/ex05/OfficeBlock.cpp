#include "OfficeBlock.hpp"
#include <iostream>
#include <stdexcept>

OfficeBlock::OfficeBlock(){};

OfficeBlock::~OfficeBlock(){};

OfficeBlock::OfficeBlock(Intern* i, Bureaucrat* b1, Bureaucrat* b2)
: intern(i), sign(b1), exc(b2) {};

void OfficeBlock::setIntern(Intern& i) {
	this->intern = &i;
}
void OfficeBlock::setSigner(Bureaucrat& b) {
	this->sign = &b;
}
void OfficeBlock::setExecutor(Bureaucrat& b) {
	this->exc = &b;
}

Bureaucrat* OfficeBlock::getSigner(void) {
	return this->sign;
}

Bureaucrat* OfficeBlock::getExecutor(void) {
	return this->exc;
}

void OfficeBlock::doBureaucracy(std::string name, std::string target)
{
	if (!intern)
		throw NoInternException();
	if (!sign)
		throw NoSignerException();
	if (!exc)
		throw NoExcException();
	Form* f = intern->makeForm(name, target);
	sign->signForm(f);
	exc->executeForm(*f);
}

const char* OfficeBlock::NoInternException::what() const throw() {
		return ("Intern NOT found\n");}

const char* OfficeBlock::NoSignerException::what() const throw() {
		return ("Signer NOT found\n");}

const char* OfficeBlock::NoExcException::what() const throw() {
		return ("Executer NOT found\n");}
