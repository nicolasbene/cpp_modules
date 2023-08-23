/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 19:06:33 by nibenoit          #+#    #+#             */
/*   Updated: 2023/08/23 19:47:42 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	std::cout << "WrongAnimal default constructor\n";
	_type = "Default Wrong Animal";
}

WrongAnimal::WrongAnimal(const WrongAnimal& WrongAnimal)
{
	std::cout << "WrongAnimal copy constructor\n";
	_type = WrongAnimal.getType();
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal desstructor\n";
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& WrongAnimal)
{
	std::cout << "WrongAnimal copy assginment operator\n";
	_type = WrongAnimal.getType();
	return *this;
}

std::string	WrongAnimal::getType(void) const
{
	return _type;
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "wrong animal sound" << std::endl;
}

