/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 19:12:18 by nibenoit          #+#    #+#             */
/*   Updated: 2023/08/23 19:48:00 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	std::cout << "WrongCat default constructor\n";
	_type = "Wrong Cat";
}

WrongCat::WrongCat(const WrongCat& WrongCat)
{
	std::cout << "WrongCat copy constructor\n";
	*this = WrongCat;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat desstructor\n";
}

WrongCat& WrongCat::operator=(const WrongCat& WrongCat)
{
	std::cout << "WrongCat copy assginment operator\n";
	_type = WrongCat._type;
	return *this;
}

void WrongCat::makeSound(void) const
{
	std::cout << "wrongcat miaou" << std::endl;
}