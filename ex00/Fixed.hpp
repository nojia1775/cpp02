#ifndef FIXED_H

# define FIXED_H

# include <iostream>

class	Fixed
{
	private:
		int			fixed_point;
		static const int	fractional_bits = 8;
	public:
					Fixed(void);
					~Fixed(void);

					Fixed(const Fixed &other);
					Fixed&	operator=(const Fixed &other);

		int			getRawBits(void) const;
		void			setRawBits(const int raw);
};


#endif