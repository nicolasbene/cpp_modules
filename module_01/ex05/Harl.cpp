/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:14:33 by nibenoit          #+#    #+#             */
/*   Updated: 2023/08/09 16:37:21 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::complain(std::string level)
{
	std::string levels[4] = {"debug", "info", "warning", "error"};
	funcPTR	functions[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (int i=0; i < 4; i++) {
		if (levels[i] == level)
			(this->*functions[i])();
	}
}

void	Harl::debug(void)
{
	std::cout << "[DEBUG]: blue message\n";
}

void	Harl::info(void)
{
	std::cout << "[INFO]: green message\n";
}

void	Harl::warning(void)
{
	std::cout << "[WARNING]: orange message\n";
}

void	Harl::error(void)
{
	std::cout << "[ERROR]: red message\n";
}
