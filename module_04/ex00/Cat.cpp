/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:53:54 by nibenoit          #+#    #+#             */
/*   Updated: 2023/08/23 19:48:38 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << "Cat default constructor\n";
	_type = "Cat";
}
Cat::Cat(const Cat& cat)
{
	std::cout << "Cat copy constructor\n";
	*this = cat;
}

Cat::~Cat(void)
{
	std::cout << "Cat desstructor\n";
}

Cat& Cat::operator=(const Cat& cat)
{
	std::cout << "Cat copy assginment operator\n";
	_type = cat._type;
	return *this;
}

void Cat::makeSound(void) const
{
	std::cout << "miaou" << std::endl;
}
