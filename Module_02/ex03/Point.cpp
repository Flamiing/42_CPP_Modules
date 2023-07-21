/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:58:52 by alaaouam          #+#    #+#             */
/*   Updated: 2023/07/21 18:38:14 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(0), _y(0)
{
	
}

Point::Point(const float num1, const float num2) : _x(num1), _y(num2)
{
	
}

Point::Point(const Point& other) : _x(other._x), _y(other._y)
{
	
}

Point& Point::operator=(const Point &other)
{
	if (this != &other)
	{
		(Fixed)_x = other._x;
		(Fixed)_y = other._y;
	}
	return *this;
}

Point::~Point(void)
{
	
}

float Point::getY(void) const
{
	return this->_y.toFloat();	
}

float Point::getX(void) const
{
	return this->_x.toFloat();	
}