#include "Fixed.hpp"

int main() {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	
	std::cout << b << std::endl;
	Fixed c = Fixed(0.0f);
	c++;
	std::cout << c << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}
