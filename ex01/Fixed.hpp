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
		~Fixed();
		Fixed(const Fixed &copy);
		Fixed& operator=(const Fixed &other);

		int getRawBits( void ) const;
		void setRawBits ( int const raw );
};

#endif