/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:33:43 by codespace         #+#    #+#             */
/*   Updated: 2024/09/27 15:41:40 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

class	Point
{
	private:
		const Fixed	x;
		const Fixed	y;

	public:
		Point(void);
		Point(const Fixed a, const Fixed b);
		Point(Point &other);
		~Point(void);
		
		Point	&operator=(const Point &other);
		Fixed	getX(void) const;
		Fixed	getY(void) const;
};