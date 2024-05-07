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
		Fixed(const Fixed &other);
		Fixed(const int n);
		Fixed(const float n);
		Fixed&	operator=(const Fixed &other);
		~Fixed(void);
		int	getRawBits(void) const;
		void	setRawBits(const int raw);
		float	toFloat(void) const;
		int	toInt(void) const;
};

std::ostream& operator<<(std::ostream &out, const Fixed &fixed);

#endif