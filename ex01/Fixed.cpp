#include "Fixed.hpp"

int Fixed::toInt(void) const
{
	return n + x /100;
}

float Fixed::toFloat(void) const
{
	return (float)n / (1 << x);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(): n(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int otherx)
{
	std::cout << "Int constructor called" << std::endl;
	this->n = otherx;
}

Fixed::Fixed(const float otherx)
{
	std::cout << "Float constructor called" << std::endl;
	n = (int)(otherx * (1 << x));
}

Fixed::Fixed(const Fixed &copy)
{
	 std::cout << "Copy constructor called" << std::endl;
	 this->n = copy.getRawBits();
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->n);
}

void Fixed::setRawBits ( int const raw )
{
	this->n = raw;
}

Fixed& Fixed::operator=(const Fixed &other)
{
	std::cout << "Assignation operator called" << std::endl;
	this->n = other.getRawBits();
	return *this;
}