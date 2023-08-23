/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 19:45:36 by nibenoit          #+#    #+#             */
/*   Updated: 2023/08/23 15:52:15 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void): ScavTrap("John Doe_clap_name"), FragTrap("John Doe_clap_name")
{
	std::cout << "DiamondTrap default constructor called\n";
	_name = "John Doe";
	_health = 100;
	_energy = 50;
	_attack = 30;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name")
{
	std::cout << "DiamondTrap constructor called\n";
	_name = name;
	_health = 100;
	_energy = 50;
	_attack = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap& diamondtrap): ClapTrap(diamondtrap), ScavTrap(diamondtrap), FragTrap(diamondtrap)
{
	std::cout << "DiamondTrap clone constructor called\n";
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& diamondtrap)
{
	std::cout << "DiamondTrap copy assignment operator called\n";
	ClapTrap::operator=(diamondtrap);
	return *this;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap destructor called\n";
}

void	DiamondTrap::whoAmI(void)
{ 
	std::cout << "DiamondTrap " << _name << " aka " << ClapTrap::_name << std::endl;
}
