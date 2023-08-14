/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 14:47:51 by nibenoit          #+#    #+#             */
/*   Updated: 2023/08/14 17:11:35 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"

void	given_main(void)
{
	Fixed		a;
	Fixed const	b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max(a, b) << std::endl;
}

void	my_main(void)
{
	Fixed	a(12.23f);
	Fixed	b(17.89f);

	std::cout << "Tests on operators +, -, *, /: \n";
	std::cout << a << " + " << b << " = " << a + b << std::endl;
	std::cout << a << " - " << b << " = " << a - b << std::endl;
	std::cout << a << " * " << b << " = " << a * b << std::endl;
	std::cout << a << " / " << b << " = " << a / b << std::endl;


	Fixed	c(a);
	std::cout << "\nTests on operators <, >, ==, !=, >=, <=:\n";
	std::cout << a << " < " << b << " = " << (a < b) << std::endl;
	std::cout << b << " < " << a << " = " << (b < a) << std::endl;
	std::cout << a << " > " << b << " = " << (a > b) << std::endl;
	std::cout << b << " > " << a << " = " << (b > a) << std::endl;
	std::cout << a << " == " << b << " = " << (a == b) << std::endl;
	std::cout << a << " == " << c << " = " << (a == c) << std::endl;
	std::cout << a << " != " << b << " = " << (a != b) << std::endl;
	std::cout << a << " != " << c << " = " << (a != c) << std::endl;
	std::cout << a << " >= " << b << " = " << (a >= b) << std::endl;
	std::cout << a << " >= " << c << " = " << (a >= c) << std::endl;
	std::cout << a << " <= " << b << " = " << (a <= b) << std::endl;
	std::cout << a << " <= " << c << " = " << (a <= c) << std::endl;

	std::cout << "\nTests on operators ++x, x++, --x, x--:\n";
	std::cout << "a = " << a << std::endl;
	std::cout << "++a = " << ++a << std::endl;
	std::cout << "a++ = " << a++ << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "--a = " << --a << std::endl;
	std::cout << "a-- = " << a-- << std::endl;
	std::cout << "a = " << a << std::endl;

	std::cout << "\nTests on min, max functions:\n";
	std::cout << "Min(" << a << ", " << b << ") = " << Fixed::min(a, b) << std::endl; 
	std::cout << "Max(" << a << ", " << b << ") = " << Fixed::max(a, b) << std::endl; 
}

int	main(void)
{
	my_main();
	return 0;
}
