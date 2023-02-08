#include "Fixed.hpp"

int Fixed::toInt(void) const
{
	int tmp = n;
	tmp >>= x;
	return tmp;
}

float Fixed::toFloat(void) const
{
	//return static_cast<float>(x) / n;
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

Fixed::Fixed(const int otherx): n(otherx << 8)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float otherx)
{
	std::cout << "Float constructor called" << std::endl;
	n = roundf(otherx * (1 << x));
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

std::ostream& operator<<(std::ostream& out, const Fixed& Fixed)
{
	out << Fixed.toFloat();
	return out;
}


Fixed& Fixed::operator=(const Fixed &other)
{
	std::cout << "Assignation operator called" << std::endl;
	this->n = other.getRawBits();
	return *this;
}