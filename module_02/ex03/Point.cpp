/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 14:49:12 by nibenoit          #+#    #+#             */
/*   Updated: 2023/08/14 17:26:34 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.h"

Point::Point(void): _x(Fixed(0)), _y(Fixed(0)) {}

Point::Point(const Point& point): _x(point.getX()), _y(point.getY()) {}

Point&	Point::operator=(const Point& point)
{
	(void)point;
	return *this;
}

Point::~Point(void) {}

Point::Point(float x, float y): _x(Fixed(x)), _y(Fixed(y)) {}

Fixed	Point::getX(void) const
{
	return _x;
}

Fixed	Point::getY(void) const
{
	return _y;
}
