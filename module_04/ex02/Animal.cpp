/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:35:46 by nibenoit          #+#    #+#             */
/*   Updated: 2023/08/24 17:04:21 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
	std::cout << "Animal default constructor\n";
	_type = "Default Animal";
}

Animal::Animal(const Animal& animal)
{
	std::cout << "Animal copy constructor\n";
	_type = animal._type;
}

Animal&	Animal::operator=(const Animal& animal)
{
	std::cout << "Animal copy assginment operator\n";
	_type = animal._type;
	return *this;
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor\n";
}

void Animal::makeSound(void) const
{
	std::cout << "animal sound" << std::endl;
}

std::string Animal::getType(void) const
{
	return _type;
}