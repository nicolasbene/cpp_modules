/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:12:38 by nibenoit          #+#    #+#             */
/*   Updated: 2023/09/12 18:29:30 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <typeinfo>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*	generate(void)
{
	int		number;
	Base*	base = NULL;

	srand(time(NULL));
	number = rand() % 3;
	switch (number) {
		case 0:
			std::cout << "Creating an A\n";
			base = new A();
			break;
		case 1:
			std::cout << "Creating a B\n";
			base = new B();
			break;
		case 2:
			std::cout << "Creating a C\n";
			base = new C();
			break;
		default:
			base = NULL;
	}
	return base;
}

void	identify(Base* p)
{
	A*	a = dynamic_cast<A*>(p);
	B*	b = dynamic_cast<B*>(p);
	C*	c = dynamic_cast<C*>(p);
	if (a != NULL)
		std::cout << "Pointer is an A\n";
	else if (b != NULL)
		std::cout << "Pointer is a B\n";
	else if (c != NULL)
		std::cout << "Pointer is a C\n";
}

void	identify(Base& p)
{
	try {
		A&	a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "Ref is an A\n";
	} catch (std::bad_cast& e) {}

	try {
		B&	b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "Ref is a B\n";
	} catch (std::bad_cast& e) {}

	try {
		C&	c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "Ref is a C\n";
	} catch (std::bad_cast& e) {}
}

int	main(void)
{
	Base	*base;

	base = generate();
	identify(base);
	identify(*base);
	if (base)
		delete base;
	return 0;
}
