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
		~Fixed();
		int getRawBits( void ) const;
		float toFloat( void ) const;
		 int toInt( void ) const;
		void setRawBits( int const raw );
};

std::ostream& operator<<(std::ostream& out_stream, const Fixed& obj);

#endif
