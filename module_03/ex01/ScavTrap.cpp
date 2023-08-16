/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 18:15:29 by nibenoit          #+#    #+#             */
/*   Updated: 2023/08/16 19:32:03 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void): ClapTrap()
{
	std::cout << "ScavTrap default constructor called\n";
	_health = 100;
	_energy = 50;
	_attack = 20;
}

ScavTrap::ScavTrap(const ScavTrap& scavtrap)
{
	std::cout << "ScavTrap clone constructor called\n";
	*this = scavtrap;
}

ScavTrap::ScavTrap(std::string name)
{
	std::cout << "ScavTrap parameter constructor called\n";
	_name = name;
	_health = 100;
	_energy = 50;
	_attack = 20;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& scavtrap)
{
	std::cout << "ScavTrap copy assginment operator called\n";
	_name = scavtrap.getName();
	_health = scavtrap.getHealth();
	_energy = scavtrap.getEnergy();
	_attack = scavtrap.getAttack();
	return (*this);
}


ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called\n";

}

void	guardGate(void)
{
	std::cout << "YOO\n";
}