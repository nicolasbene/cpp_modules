/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:35:01 by nibenoit          #+#    #+#             */
/*   Updated: 2023/09/12 18:19:06 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdint.h>
#include "Data.hpp"

uintptr_t	serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data*	deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}

int	main(void)
{
	Data		*data;
	Data		*data2;
	uintptr_t	raw;

	data = new Data("Jane");
	std::cout << "Data* = " << data << "\n";
	raw = serialize(data);
	std::cout << "uintptr_t = " << (void *)raw << "\n";
	data2 =  deserialize(raw);
	std::cout << "Deserialize Data* = " << data << "\n";
	if (data == data2)
		std::cout << "Equal\n";
	else
		std::cout << "Not equal\n";
	if (data)
		delete data;
	return 0;
}
