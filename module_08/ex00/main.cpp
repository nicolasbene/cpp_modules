/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:50:12 by nibenoit          #+#    #+#             */
/*   Updated: 2023/09/14 11:07:17 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>

int main()
{
	std::vector<int> v;
	std::vector<int>::iterator it;

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	try
	{
		it = easyfind(v, 3);
		std::cout << *it << std::endl;
	} catch(const std::exception& e)
	{
		std::cerr << "Error could not find the element" << std::endl;
	}

	try
	{
		it = easyfind(v, 42);
		std::cout << *it << std::endl;
	} catch(const std::exception& e)
	{
		std::cerr << "Error could not find the element" << std::endl;
	}

	return (0);
}