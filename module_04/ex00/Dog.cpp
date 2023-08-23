/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 19:01:47 by nibenoit          #+#    #+#             */
/*   Updated: 2023/08/23 19:48:50 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << "Dog default constructor\n";
	_type = "Dog";
}

Dog::Dog(const Dog& dog)
{
	std::cout << "Dog copy constructor\n";
	*this = dog;
}

Dog::~Dog(void)
{
	std::cout << "Dog desstructor\n";
}

Dog& Dog::operator=(const Dog& dog)
{
	std::cout << "Dog copy assginment operator\n";
	_type = dog._type;
	return *this;
}

void Dog::makeSound(void) const
{
	std::cout << "woof woof" << std::endl;
}