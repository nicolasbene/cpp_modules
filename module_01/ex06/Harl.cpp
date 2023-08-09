/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:14:33 by nibenoit          #+#    #+#             */
/*   Updated: 2023/08/09 16:39:23 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::complain(std::string level)
{
	int	i;
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	i = 0;
	while (i < 4) {
		if (levels[i] == level)
			break;
		i++;
	}
	switch(i) {
		case 0:
			debug();
		case 1:
			info();
		case 2:
			warning();
		case 3:
			error();
			break;
		default:
			std::cout << "[Probably complaining about insignificant problems]\n";
	}
}

void	Harl::debug(void)
{
	std::cout << "[DEBUG]" << ": blue message\n";
}

void	Harl::info(void)
{
	std::cout <<  "[INFO]" << ": green message\n";
}

void	Harl::warning(void)
{
	std::cout << "[WARNING]" << ": orange message\n";
}

void	Harl::error(void)
{
	std::cout << "[ERROR]" << ": red message\n";
}
