#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::bp = 8;

Fixed::Fixed(void) : value(0) {}

Fixed::~Fixed(void) {}

Fixed::Fixed(Fixed const & src) {
	*this = src;}

Fixed & Fixed::operator=(Fixed const & rhs) {
	if (this != &rhs)
		this->value = rhs.getRawBits();
	return (*this);}

int Fixed::getRawBits(void) const {
	return (this->value);}

void Fixed::setRawBits(int const raw) {
	this->value = raw;}

Fixed::Fixed(const int i) : value(i << bp) {}

Fixed::Fixed(const float f) : value(roundf(f * pow(2, this->bp))) {}

float Fixed::toFloat( void ) const {
	return ((float)this->value / pow(2, this->bp));}

int Fixed::toInt( void ) const {
	return (this->value >> this->bp);}

bool	Fixed::operator>(Fixed const & rhs) const {
	return (this->toFloat() > rhs.toFloat() ? true : false);}

bool	Fixed::operator<(Fixed const & rhs) const {
	return (this->toFloat() < rhs.toFloat() ? true : false);}

bool	Fixed::operator>=(Fixed const & rhs) const {
	return (this->toFloat() >= rhs.toFloat() ? true : false);}

bool	Fixed::operator<=(Fixed const & rhs) const {
	return (this->toFloat() <= rhs.toFloat() ? true : false);}

bool	Fixed::operator==(Fixed const & rhs) const {
	return (this->toFloat() == rhs.toFloat() ? true : false);}

bool	Fixed::operator!=(Fixed const & rhs) const {
	return (this->toFloat() != rhs.toFloat() ? true : false);}

float	Fixed::operator+(Fixed const & rhs) const {
	return (this->toFloat() + rhs.toFloat());}

float	Fixed::operator-(Fixed const & rhs) const {
	return (this->toFloat() - rhs.toFloat());}

float	Fixed::operator*(Fixed const & rhs) const {
	return (this->toFloat() * rhs.toFloat());}

float	Fixed::operator/(Fixed const & rhs) const {
	return (this->toFloat() / rhs.toFloat());}

Fixed	Fixed::operator++(void) {
	this->value++;
	return (*this);}

Fixed	Fixed::operator++(int n) {
	Fixed tmp;

	(void)n;
	tmp = Fixed(this->toFloat());
	this->value++;
	return (tmp);}

Fixed	Fixed::operator--(void) {
	this->value--;
	return (*this);}

Fixed	Fixed::operator--(int n) {
	Fixed tmp;

	(void)n;
	tmp = Fixed(this->toFloat());
	this->value--;
	return (tmp);}

Fixed &Fixed::min(Fixed & f1, Fixed & f2) {
	if (f1 <= f2)
		return (f1);
	return (f2);}

Fixed &Fixed::max(Fixed & f1, Fixed & f2) {
	if (f1 >= f2)
		return (f1);
	return (f2);}

const Fixed &Fixed::min(Fixed const & f1, Fixed const & f2) {
	if (f1 <= f2)
		return (f1);
	return (f2);}

const Fixed &Fixed::max(Fixed const & f1, Fixed const & f2) {
	if (f1 >= f2)
		return (f1);
	return (f2);}

std::ostream & operator<<(std::ostream & ofs, const Fixed & fixed) {
	ofs << fixed.toFloat();
	return (ofs);}

