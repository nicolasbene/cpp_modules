/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:33:08 by nibenoit          #+#    #+#             */
/*   Updated: 2023/09/20 16:50:49 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char *av[])
{
	BitcoinExchange A;
	if (ac == 2)
	{
		try
		{
			A.ReadBase();
			A.ReadInput(av[1]);
		} catch (const BitcoinExchange::InvalidFormatException& e) {
			std::cerr << "Invalid Format Exception: " << e.what() << '\n';
		} catch (const BitcoinExchange::InvalidRateException& e) {
			std::cerr << "Invalid Rate Exception: " << e.what() << '\n';
		} catch (const std::exception& e) {
			std::cerr << "Other Exception: " << e.what() << '\n';
		}
	}
	else
		std::cerr << "Error: Invalid number of arguments\n";
}