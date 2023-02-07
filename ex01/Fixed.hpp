#ifndef Fixed_HPP
# define Fixed_HPP

# include <string>
# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int n;
		static const int x = 8;
	public:
		Fixed();
		Fixed(const int otherx);
		Fixed(const float otherx);
		~Fixed();
		Fixed(const Fixed &copy);
		Fixed& operator=(const Fixed &other);

		int getRawBits( void ) const;
		void setRawBits ( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& Fixed);

#endif