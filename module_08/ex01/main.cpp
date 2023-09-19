/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:44:48 by nibenoit          #+#    #+#             */
/*   Updated: 2023/09/19 16:27:18 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <cstdlib>
#include "Span.hpp"

int	main(void)
{
	srand(time(NULL));
	{
		std::cout << "Test for normal size list:\n";
		Span	sp(10);

		sp.addNumber(0);
		sp.addNumber(10);
		sp.addNumber(20);
		sp.addNumber(22);
		sp.addNumber(40);
		sp.addNumber(50);
		sp.addNumber(60);
		sp.addNumber(70);
		sp.addNumber(80);
		sp.addNumber(90);
		std::cout << "Shortest span: " << sp.shortestSpan() << "\n";
		std::cout << "Longest span: " << sp.longestSpan() << "\n";
	}
	{
		std::cout << "\nTest for huge size (1 000 000) random numbers:\n";
		Span	sp(1000000);

		for (unsigned int i=0; i < 1000000; i++)
			sp.addNumber(rand() % 1000000000);
		std::cout << "Shortest span: " << sp.shortestSpan() << "\n";
		std::cout << "Longest span: " << sp.longestSpan() << "\n";
	}
	{
		std::cout << "\nTest for inserting range of iterators:\n";
		int	numbers[10] = {1, 10, 20, 30, 40, 50, 60, 70, 80, 90};
		std::vector<int> vec;
		Span	sp(11);
		
		vec.insert(vec.begin(), numbers, numbers + 10);
		sp.addNumber(200);
		sp.insert(vec.begin(), vec.end());
		std::cout << "Shortest span: " << sp.shortestSpan() << "\n";
		std::cout << "Longest span: " << sp.longestSpan() << "\n";
	}
	{
		std::cout << "\nTest for error on empty Span:\n";
		Span	sp(10);

		try {
			int shortest = sp.shortestSpan();
			std::cout << "Shortest span: " << shortest << "\n";
		} catch (Span::NotEnoughSpaceException& e) {
			std::cout << "Error: could not get shortest span because " << e.what() << "\n";
		}
	}
	{
		std::cout << "\nTest for adding number to Span when full\n";
		Span	sp(3);

		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(3);
		try {
			sp.addNumber(4);
			std::cout << "Number added\n";
		} catch (Span::FullSpanException& e) {
			std::cout << "Error: could not add a number to Span because " << e.what() << "\n";
		}
	}
	return 0;
}
