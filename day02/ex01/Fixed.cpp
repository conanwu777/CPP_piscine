#include "Fixed.hpp"

const int Fixed::bp = 8;

Fixed::Fixed(void) : value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const & src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed & Fixed::operator=(Fixed const & rhs) {
	std::cout << "Assignation operator called" << std::endl;
	if (this != &rhs)
		this->value = rhs.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const {
	return (this->value);
}

void Fixed::setRawBits(int const raw) {
	this->value = raw;
}

Fixed::Fixed(const int i) : value(i << bp) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f) : value(roundf(f * pow(2, this->bp))) {
	std::cout << "Float constructor called" << std::endl;
}

float Fixed::toFloat( void ) const {
	return ((float)this->value / pow(2, this->bp));
}

int Fixed::toInt( void ) const {
	return (this->value >> this->bp);
}

std::ostream & operator<<(std::ostream & ofs, const Fixed & fixed) {
	ofs << fixed.toFloat();
	return (ofs);
}
