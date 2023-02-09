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

		//operadores aritmeticos
		Fixed operator+(const Fixed &other) const;
		Fixed operator-(const Fixed &other) const;
		Fixed operator*(const Fixed &other) const;
		Fixed operator/(const Fixed &other) const;
		//comparacion
		bool operator==(const Fixed &other) const;
		bool operator!=(const Fixed &other) const;
		bool operator<(const Fixed &other) const;
		bool operator>(const Fixed &other) const;
		bool operator<=(const Fixed &other) const;
		bool operator>=(const Fixed &other) const;

		//Operadores pre/post
		Fixed& operator++(void);
		Fixed operator++(int);
		Fixed& operator--(void);
		Fixed operator--(int);

		static const Fixed& min(const Fixed& f1, const Fixed& f2);
		static const Fixed& min(Fixed& f1, Fixed& f2);
		static const Fixed& max(const Fixed& f1, const Fixed& f2);
		static const Fixed& max(Fixed& f1, Fixed& f2);
		
		int getRawBits( void ) const;
		void setRawBits ( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& Fixed);

#endif