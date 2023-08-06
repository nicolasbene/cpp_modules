/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 19:15:35 by nibenoit          #+#    #+#             */
/*   Updated: 2023/08/06 19:58:03 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	_name = "DefaultZombie";
}

Zombie::Zombie(std::string name)
{
	_name = name;
}

Zombie::~Zombie(void)
{
	std::cout << _name << ": dies...\n";
}

void	Zombie::setName(std::string name)
{
	_name = name;
}

void	Zombie::announce(void) const
{

	std::cout << _name << ": BraiiiiiinnnzzzZ...\n";
}
