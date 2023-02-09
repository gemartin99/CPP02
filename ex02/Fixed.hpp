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
		Fixed operator+(const Fixed &other) const {
			Fixed res;
			res.n = this->n + other.n;
			return res;
		}
		Fixed operator-(const Fixed &other) const {
			Fixed res;
			res.n = this->n - other.n;
			return res;
		}
		Fixed operator*(const Fixed &other) const {
			Fixed res;
			float tmp = this->toFloat() * other.toFloat();
			res.setRawBits(roundf(tmp * (1 << x)));
			return res;
		}
		Fixed operator/(const Fixed &other) const {
			Fixed res;
			float tmp = this->toFloat() / other.toFloat();
			res.setRawBits(roundf(tmp * (1 << x)));
			return res;
		}

		//comparacion
		bool operator==(const Fixed &other) const {
			return (this->n == other.n);
		}
		bool operator!=(const Fixed &other) const {
			return !(*this == other);
		}
		bool operator<(const Fixed &other) const {
			return this->getRawBits() < other.getRawBits();
		}
		bool operator>(const Fixed &other) const {
			return this->getRawBits() > other.getRawBits();
		}
		bool operator<=(const Fixed &other) const {
			return !(*this > other);
		}
		bool operator>=(const Fixed &other) const {
			return !(*this < other);
		}

		//Operadores pre/post
		Fixed& operator++(){
			++this->n;
			return *this;
		}
		Fixed operator++(int) {
			Fixed res(*this);
			++this->n;
			return res;
		}
		Fixed& operator--(){
			--this->n;
			return *this;
		}
		Fixed operator--(int) {
			Fixed res(*this);
			--this->n;
			return res;
		}

		//static min/max
		static const Fixed& min(const Fixed& f1, const Fixed& f2) {
			if (f1 > f2)
				return (f2);
			return (f1);
		}
		static const Fixed& min(Fixed& f1, Fixed& f2) {
			if (f1 > f2)
				return (f2);
			return (f1);
		}
		static const Fixed& max(const Fixed& f1, const Fixed& f2) {
			if (f1 < f2)
				return (f2);
			return (f1);
		}
		static const Fixed& max(Fixed& f1, Fixed& f2) {
			if (f1 < f2)
				return (f2);
			return (f1);
		}
		int getRawBits( void ) const;
		void setRawBits ( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& Fixed);

#endif