/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:37:17 by codespace         #+#    #+#             */
/*   Updated: 2024/09/27 15:42:50 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point(void)
{
	this->x = Fixed();
	this->y = Fixed();
}

Point(const Fixed a, const Fixed b)
{
	this->x = a;
	this->y = b;
}

~Point(void)
{
	std::cout << "Point destructor called" << std::endl;
}

Point	&Point::operator=(const Point &other)
{
	this->x = other.getX();
	this->y = other.getY();
	return (*this);
}

Fixed	Point::getx(void) const
{
	return (this->x);
}

Fixed	Point::getY(void) const
{
	return (this->y);
}