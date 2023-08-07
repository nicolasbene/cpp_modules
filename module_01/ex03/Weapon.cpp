/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:13:54 by nibenoit          #+#    #+#             */
/*   Updated: 2023/08/07 11:22:26 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

//constructeur par default
Weapon::Weapon(void)
{
	_type = "Fists";
}

Weapon::Weapon(std::string type)
{
	_type = type;
}

//destructeur
Weapon::~Weapon(void)
{
	
}

void	Weapon::setType(std::string const type)
{
	_type = type;
}

std::string	Weapon::getType(void) const
{
	return _type;	
}
