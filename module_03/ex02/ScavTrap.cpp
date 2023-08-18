/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 18:15:29 by nibenoit          #+#    #+#             */
/*   Updated: 2023/08/18 17:04:55 by nibenoit         ###   ########.fr       */
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

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	std::cout << "ScavTrap constructor called\n";
	_health = 100;
	_energy = 50;
	_attack = 20;
}

ScavTrap::ScavTrap(const ScavTrap& scavtrap): ClapTrap(scavtrap)
{
	std::cout << "ScavTrap clone constructor called\n";
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& scavtrap)
{
	ClapTrap::operator=(scavtrap);
	std::cout << "ScavTrap copy assignment operator called\n";
	return *this;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called\n";
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << _name << " is now in gate keeper mode\n";
}

void	ScavTrap::attack(const std::string& target)
{
	if (_energy == 0 || _health == 0)
		std::cout << "ScavTrap " << _name << " cannot attack because it does not have enough energy !\n";
	else {
		_energy--;
		std::cout << "ScavTrap " << _name << " attack " << target << ", causing " << _attack << " points of damage\n";
	}
}
