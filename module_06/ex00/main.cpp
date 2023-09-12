/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:28:42 by nibenoit          #+#    #+#             */
/*   Updated: 2023/09/11 15:29:21 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Types.hpp"

void	usage(std::string prog_name)
{
	std::cout << "Usage: " << prog_name << " <value>" << std::endl;
}

int	main(int ac, char** av)
{
	Types*	types;

	if (ac != 2)
		return(usage(av[0]), 1);
	try {
		types = new Types(av[1]);
		std::cout << *types << std::endl;
		delete types;
	} catch (Types::NonNumericValueException e) {
		std::cout << "Error: could not instantiate the Types object because " << e.what() << std::endl;
	}
	return 0;
}
