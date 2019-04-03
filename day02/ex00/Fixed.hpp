#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed {
	int value;
	static const int d;

public:
	Fixed(void);
	~Fixed(void);
	Fixed(Fixed const & src);

	Fixed & operator=(Fixed const & rhs);
	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif