#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>

class Fixed
{
	private:
		int Value_; //FixedPointNumberValue
		static const int Bits_ = 8; //NumberOfFractionalBits
	public:
		Fixed();
		Fixed(const Fixed& obj);
		Fixed& operator=(const Fixed& obj);
		~Fixed();
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

#endif
