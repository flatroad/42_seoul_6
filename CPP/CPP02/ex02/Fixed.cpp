#include "Fixed.hpp"

Fixed::Fixed()
{
	// std::cout << "Default constructor called" << std::endl;
	this->Value_ = 0;
}

Fixed::Fixed(const Fixed& obj)
{ 
	// std::cout << "Copy constructor called" << std::endl;
	operator=(obj);
}

Fixed::Fixed(const int value)
{
	// std::cout << "Int constructor called" << std::endl;
	this->Value_ = value * (0x00000001 << Bits_);
}

Fixed::Fixed(const float value)
{
	// std::cout << "Float constructor called" << std::endl;
	this->Value_ = roundf(value * (0x00000001 << Bits_));
}

Fixed& Fixed::operator=(const Fixed& obj)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		this->Value_ = obj.getRawBits();
	}
	return *this;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}
		
int Fixed::getRawBits( void ) const
{
	return (this->Value_);
}

void Fixed::setRawBits( int const raw )
{
	this->Value_ = raw;
}

float Fixed::toFloat( void ) const
{
	return ((float)this->Value_ / (0x00000001 << Bits_));
}

int Fixed::toInt( void ) const
{
	return (this->Value_ / (0x00000001 << Bits_));
}

std::ostream& operator<<(std::ostream& out_stream, const Fixed& obj)
{
	out_stream << obj.toFloat();
	return (out_stream);
}

bool Fixed::operator>(const Fixed& obj) const
{
	if (this->Value_ > obj.Value_)
		return (true);
	return (false);
}

bool Fixed::operator<(const Fixed& obj) const
{
	if (this->Value_ < obj.Value_)
		return (true);
	return (false);
}

bool Fixed::operator<=(const Fixed& obj) const
{
	if (this->Value_ <= obj.Value_)
		return (true);
	return (false);
}

bool Fixed::operator>=(const Fixed& obj) const
{
	if (this->Value_ >= obj.Value_)
		return (true);
	return (false);
}

bool Fixed::operator==(const Fixed& obj) const
{
	if (this->Value_ == obj.Value_)
		return (true);
	return (false);
}

bool Fixed::operator!=(const Fixed& obj) const
{
	if (this->Value_ != obj.Value_)
		return (true);
	return (false);
}

Fixed	Fixed::operator+(const Fixed obj) const
{
	return (this->toFloat() + obj.toFloat());
}

Fixed	Fixed::operator-(const Fixed obj) const
{
	return (this->toFloat() - obj.toFloat());
}

Fixed	Fixed::operator*(const Fixed obj) const
{
	return (this->toFloat() * obj.toFloat());
}

Fixed	Fixed::operator/(const Fixed obj) const
{
	return (this->toFloat() / obj.toFloat());
}

Fixed& Fixed::operator++() 
{
	this->Value_++;
	return (*this);
}

Fixed& Fixed::operator--()
{
	this->Value_--;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed old(*this);
	this->operator++();
	return (old);
}

Fixed Fixed::operator--(int)
{
	Fixed old(*this);
	this->operator--();
	return (old);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a.operator<(b))
		return (a);
	return (b);
}

const Fixed& Fixed::min(Fixed const& a, Fixed const& b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a.operator<(b))
		return (b);
	return (a);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a < b)
		return (b);
	return (a);
}
