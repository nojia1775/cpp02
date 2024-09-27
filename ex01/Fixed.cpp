#include "Fixed.hpp"

Fixed::Fixed(void)
{
	this->fixed_point = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	this->fixed_point = other.fixed_point;
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixed_point = n << this->fractional_bits;
}

Fixed::Fixed(const float n)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixed_point = roundf(n * (1 << this->fractional_bits));
}

Fixed&	Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &other)
		this->fixed_point = other.fixed_point;
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixed_point);
}

void	Fixed::setRawBits(const int raw)
{
	this->fixed_point = raw;
}

float	Fixed::toFloat(void) const
{
	return (roundf((float)this->fixed_point) / (1 << this->fractional_bits));
}

int	Fixed::toInt(void) const
{
	return (fixed_point >> fractional_bits);
}

std::ostream&	operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}