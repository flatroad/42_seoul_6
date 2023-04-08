#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->Value_ = 0;
}

Fixed::Fixed(const Fixed& obj)
{ 
	std::cout << "Copy constructor called" << std::endl;
	operator=(obj);
}

Fixed& Fixed::operator=(const Fixed& obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		this->Value_ = obj.getRawBits();
	}
	return *this;
}
		
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}
		
int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->Value_);
}

void Fixed::setRawBits( int const raw )
{
	this->Value_ = raw;
}