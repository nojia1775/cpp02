#ifndef FIXED_H

# define FIXED_H

# include <iostream>
# include <cmath>

class	Fixed
{
	private:
		int			fixed_point;
		static const int	fractional_bits = 8;
	public:
					Fixed(void);
					~Fixed(void);

					Fixed(const Fixed &other);
					Fixed(const int n);
					Fixed(const float n);

		Fixed&			operator=(const Fixed &other);
		bool			operator>(const Fixed &other) const;
		bool			operator<(const Fixed &other) const;
		bool			operator>=(const Fixed &other) const;
		bool			operator<=(const Fixed &other) const;
		bool			operator==(const Fixed &other) const;
		bool			operator!=(const Fixed &other) const;
		Fixed			operator+(const Fixed &other) const;
		Fixed			operator-(const Fixed &other) const;
		Fixed			operator*(const Fixed &other) const;
		Fixed			operator/(const Fixed &other) const;
		Fixed			operator++(int);
		Fixed			&operator++(void);
		Fixed			operator--(int);
		Fixed			&operator--(void);
		int			getRawBits(void) const;
		void			setRawBits(const int raw);
		float			toFloat(void) const;
		int			toInt(void) const;
		static Fixed		&min(Fixed &a, Fixed &b);
		static Fixed		&min(const Fixed &a, const Fixed &b);
		static Fixed		&max(Fixed &a, Fixed &b);
		static Fixed		&max(const Fixed &a, const Fixed &b);
};

std::ostream	&operator<<(std::ostream &out, const Fixed &fixed);

#endif