/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 19:10:07 by nibenoit          #+#    #+#             */
/*   Updated: 2023/08/07 10:44:13 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string	string;
	std::string	*stringPTR;
	std::string	&stringREF = string;

	string = "HI THIS IS BRAIN";
	stringPTR = &string;
	std::cout << "Memory address of the string: " << &string << "\n";
	std::cout << "Memory address held by stringPTR: " << stringPTR << "\n";
	std::cout << "Memory address held by stringREF: " << &stringREF << "\n";
	std::cout << "Value of string: " << string << "\n";
	std::cout << "Value pointed by stringPTR: " << *stringPTR << "\n";
	std::cout << "Value pointed by stringREF: " << stringREF << "\n";
	return 0;
}
