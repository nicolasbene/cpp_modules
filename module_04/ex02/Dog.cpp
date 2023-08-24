/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 19:01:47 by nibenoit          #+#    #+#             */
/*   Updated: 2023/08/24 16:25:49 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << "Dog default constructor called\n";
	_type = "Dog";
	_brain = new Brain();
}

Dog::Dog(const Dog& dog): Animal(dog)
{
	std::cout << "Dog clone constructor called\n";
	*this = dog;
}

Dog::Dog(std::string name)
{
	std::cout << "Dog name constructor called\n";
	_name = name;
	_type = "Dog";
	_brain = new Brain();
}

Dog&	Dog::operator=(const Dog& dog)
{
	std::cout << "Dog copy assignment operator called\n";
	_type = dog._type;
	_brain = new Brain(*dog._brain);
	return *this;
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called\n";
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

std::string	Dog::getIdea(int i) const
{
	return _ideas[i];
}

void	Dog::setIdea(int i, std::string idea)
{
	_ideas[i] = idea;
}