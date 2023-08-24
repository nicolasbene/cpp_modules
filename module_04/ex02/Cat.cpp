/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:53:54 by nibenoit          #+#    #+#             */
/*   Updated: 2023/08/24 16:55:07 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << "Cat default constructor\n";
	_type = "Cat";
	_brain = new Brain();
}

Cat::Cat(const Cat& cat)
{
	std::cout << "Cat clone constructor\n";
	*this = cat;
}

Cat&	Cat::operator=(const Cat& cat)
{
	std::cout << "Cat copy assignment operator\n";
	_type = cat._type;
	_brain = new Brain(*cat._brain);
	return *this;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor\n";
	delete _brain;
}

Brain*	Cat::getBrain(void) const
{
	return _brain;
}

void	Cat::makeSound(void) const
{
	std::cout << "miaouw" << std::endl;
}
