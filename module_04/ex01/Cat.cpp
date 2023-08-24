/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:53:54 by nibenoit          #+#    #+#             */
/*   Updated: 2023/08/24 16:01:29 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << "Cat default constructor\n";
	_type = "Cat";
	_brain = new Brain();
}

Cat::Cat(const Cat& cat) : Animal(cat)
{
	std::cout << "Cat copy constructor\n";
	*this = cat;
}

Cat::~Cat(void)
{
	std::cout << "Cat desstructor\n";
	delete _brain;
}

Cat&	Cat::operator=(const Cat& cat)
{
	std::cout << "Cat copy assginment operator\n";
	_type = cat._type;
	_brain = new Brain(*cat._brain);
	return *this;
}

Brain*	Cat::getBrain(void) const
{
	return _brain;
}

void	Cat::makeSound(void) const
{
	std::cout << "miaou" << std::endl;
}

std::string	Cat::getIdea(int i) const
{
	return _ideas[i];
}

void	Cat::setIdea(int i, std::string idea)
{
	_ideas[i] = idea;
}