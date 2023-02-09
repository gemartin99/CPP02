#include <iostream>
#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	std::cout << std::endl;
	Fixed b;
	std::cout << std::endl;
	Fixed c  = Fixed();
	std::cout << std::endl;
	
	c = b;

	std::cout << std::endl;
	std::cout << a.getRawBits() << std::endl;
	std::cout << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << std::endl;
	std::cout << c.getRawBits() << std::endl;
	std::cout << std::endl;
	
	return 0;
}