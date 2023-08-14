/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 14:45:49 by nibenoit          #+#    #+#             */
/*   Updated: 2023/08/14 17:26:33 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.h"

int	main(void)
{
	Point	a(2, 0);
	Point	b(3, 2);
	Point	c(1, 2);

	Point	d(2, 1);
	Point	e(2, 2.1);
	Point	f(2, 2);
	Point	g(2, 0);
	std::cout << "The Triangle is a(" << a.getX() << "," << a.getY() << "), b(" << b.getX() << "," << b.getY() << "), c(";
	std::cout << c.getX() << "," << c.getY() << "):\n";
	std::cout << "The point (" << d.getX() << "," << d.getY() << ") is in triangle ? " << bsp(a, b, c, d) << std::endl;
	std::cout << "The point (" << e.getX() << "," << e.getY() << ") is in triangle ? " << bsp(a, b, c, e) << std::endl;
	std::cout << "The point (" << f.getX() << "," << f.getY() << ") is in triangle ? " << bsp(a, b, c, f) << std::endl;
	std::cout << "The point (" << g.getX() << "," << g.getY() << ") is in triangle ? " << bsp(a, b, c, g) << std::endl;
	return 0;
}
