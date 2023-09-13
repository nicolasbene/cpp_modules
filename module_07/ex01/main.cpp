/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:35:20 by nibenoit          #+#    #+#             */
/*   Updated: 2023/09/13 10:35:43 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

int main()
{
	int		int_array[5] = {0, 1, 2, 3, 4};
	float	float_array[5] = {0.0f, 1.0f, 2.0f, 3.0f, 4.0f};
	char	char_array[5] = {'a', 'b', 'c', 'd', 'e'};

	std::cout << "int_array: ";
	iter(int_array, 5, print);
	std::cout << std::endl;

	std::cout << "float_array: ";
	iter(float_array, 5, print);
	std::cout << std::endl;

	std::cout << "char_array: ";
	iter(char_array, 5, print);
	std::cout << std::endl;

	return (0);
}