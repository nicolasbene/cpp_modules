/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:33:08 by nibenoit          #+#    #+#             */
/*   Updated: 2023/09/20 22:13:45 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
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
        } catch (const BitcoinExchange::InvalidFileException& e) {
			std::cerr << "Invalid File Exception: " << e.what() << '\n';
		}
    }
    else
        std::cerr << "Error: could not open file";
}