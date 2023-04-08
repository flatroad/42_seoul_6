#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
	private:
		float Value_; //FixedPointNumberValue
		static const int Bits_ = 8; //NumberOfFractionalBits

	public:
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed& obj);
		Fixed& operator=(const Fixed& obj);
		bool operator>(const Fixed& obj) const;
		bool operator<(const Fixed& obj) const;
		bool operator>=(const Fixed& obj) const;
		bool operator<=(const Fixed& obj) const;
		bool operator==(const Fixed& obj) const;
		bool operator!=(const Fixed& obj) const;
		Fixed operator+(const Fixed obj) const;
		Fixed operator-(const Fixed obj) const;
		Fixed operator*(const Fixed obj) const;
		Fixed operator/(const Fixed obj) const;
		Fixed& operator++();
		Fixed& operator--();
		Fixed operator++(int);
		Fixed operator--(int);
		static Fixed& min(Fixed& a, Fixed& b);
    	static const Fixed& min(Fixed const& a, Fixed const& b);
    	static Fixed& max(Fixed& a, Fixed& b);
    	static const Fixed& max(Fixed const& a, Fixed const& b);
		~Fixed();
		int getRawBits( void ) const;
		float toFloat( void ) const;
		 int toInt( void ) const;
		void setRawBits( int const raw );
};

std::ostream& operator<<(std::ostream& out_stream, const Fixed& obj);

#endif
