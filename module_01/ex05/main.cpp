/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:07:29 by nibenoit          #+#    #+#             */
/*   Updated: 2023/08/09 16:28:58 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl harl;

	harl.complain("info");
	harl.complain("debug");
	harl.complain("warning");
	harl.complain("error");
	harl.complain("debug");
	harl.complain("debug");
	harl.complain("error");
	harl.complain("error");
	harl.complain("error");
	harl.complain("warning");
	harl.complain("warning");
	harl.complain("warning");
	harl.complain("info");
	harl.complain("warning");
	harl.complain("info");
	harl.complain("info");
	return 0;
}
