#include "Fixed.hpp"

Fixed::Fixed(void)
{
	this->fixed_point = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	this->fixed_point = other.getRawBits();
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
		this->fixed_point = other.getRawBits();
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

bool	Fixed::operator>(const Fixed &other) const
{
	return (this->fixed_point > other.getRawBits());
}

bool	Fixed::operator<(const Fixed &other) const
{
	return (this->fixed_point < other.getRawBits());
}

bool	Fixed::operator<=(const Fixed &other) const
{
	return (this->fixed_point <= other.getRawBits());
}

bool	Fixed::operator>=(const Fixed &other) const
{
	return (this->fixed_point >= other.getRawBits());
}

bool	Fixed::operator==(const Fixed &other) const
{
	return (this->fixed_point == other.getRawBits());
}

bool	Fixed::operator!=(const Fixed &other) const
{
	return (this->fixed_point != other.getRawBits());
}

Fixed	Fixed::operator+(const Fixed &other) const
{
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed	Fixed::operator-(const Fixed &other) const
{
	return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed	Fixed::operator*(const Fixed &other) const
{
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed	Fixed::operator/(const Fixed &other) const
{
	return (Fixed(this->toFloat() / other.toFloat()));
}

std::ostream&	operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return ((Fixed &)a);
	else
		return ((Fixed &)b);
}

Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return ((Fixed &)a);
	else
		return ((Fixed &)b);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);
	this->fixed_point++;
	return (tmp);
}

Fixed	&Fixed::operator++(void)
{
	(this->fixed_point)++;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);
	(this->fixed_point)--;
	return (tmp);
}

Fixed	&Fixed::operator--(void)
{
	(this->fixed_point)--;
	return (*this);
}