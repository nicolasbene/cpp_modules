/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 19:01:47 by nibenoit          #+#    #+#             */
/*   Updated: 2023/08/24 16:50:39 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << "Dog default constructor\n";
	_type = "Dog";
	_brain = new Brain();
}

Dog::Dog(const Dog& dog)
{
	std::cout << "Dog clone constructor\n";
	*this = dog;
}

Dog&	Dog::operator=(const Dog& dog)
{
	std::cout << "Dog copy assignment operator\n";
	_type = dog._type;
	_brain = new Brain(*dog._brain);
	return *this;
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor\n";
	delete _brain;
}

Brain*	Dog::getBrain(void) const
{
	return _brain;
}

void	Dog::makeSound(void) const
{
	std::cout << "wouf wouf" << std::endl;
}
