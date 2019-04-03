#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <cmath>

class Fixed {
	int value;
	static const int bp;

public:
	Fixed(void);
	~Fixed(void);
	Fixed(Fixed const & src);
	Fixed(const int i);
	Fixed(const float f);

	Fixed & operator=(Fixed const & rhs);
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat( void ) const;
	int toInt( void ) const;

};

std::ostream & operator<<(std::ostream & ofs, const Fixed & fixed);

#endif