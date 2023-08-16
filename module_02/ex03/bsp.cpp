/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 14:48:28 by nibenoit          #+#    #+#             */
/*   Updated: 2023/08/15 13:46:07 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.h"

Fixed	sign(Point a, Point b, Point c)
{
	return (a.getX() - c.getX()) * (b.getY() - c.getY()) - (b.getX() - c.getX()) * (a.getY() - c.getY());
}

bool	is_in_segment(Point a, Point b, Point c)
{

	Fixed	coef_a_b = ((b.getY() - a.getY()) / (b.getX() - a.getX()));
	Fixed	coef_b_c = ((b.getY() - c.getY()) / (b.getX() - c.getX()));

	return (coef_a_b == coef_b_c);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	d1, d2, d3;
	bool	has_neg, has_pos, is_in_triangle;

	d1 = sign(point, a, b);
	d2 = sign(point, b, c);
	d3 = sign(point, c, a);

	has_neg = (d1 < Fixed(0)) || (d2 < Fixed(0)) || (d3 < Fixed(0));
	has_pos = (d1 > Fixed(0)) || (d2 > Fixed(0)) || (d3 > Fixed(0));

	is_in_triangle = !(has_neg && has_pos);
	if (is_in_triangle) {
		if (is_in_segment(a, b, point) || is_in_segment(a, c, point) || is_in_segment(b, c, point))
			return false;
		return true;
	}
	return false;
}
