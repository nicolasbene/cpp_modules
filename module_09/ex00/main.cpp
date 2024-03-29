/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:33:08 by nibenoit          #+#    #+#             */
/*   Updated: 2023/09/21 15:32:54 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "BitcoinExchange.hpp"

int main(int ac, char *av[])
{
	BitcoinExchange Bitcoin;
	if (ac != 2)
		std::cerr << "Usage: ./btc [inpu.txt]" << std::endl;
	else
	{
		try
		{
			Bitcoin.ReadBase();
			Bitcoin.ReadInput(av[1]);
		} catch (const BitcoinExchange::InvalidFileException& e) {
			std::cerr << "Invalid File Exception: " << e.what() << '\n';
		}
	}
	return (0);
}