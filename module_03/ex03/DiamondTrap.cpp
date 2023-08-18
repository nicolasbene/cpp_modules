/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 19:45:36 by nibenoit          #+#    #+#             */
/*   Updated: 2023/08/18 18:42:44 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void): ClapTrap("John Doe_clap_name")
{
	std::cout << "DiamondTrap default constructor called\n";
	_name = "John Doe";
	this->_health = FragTrap::_attack;
	this->_energy = ScavTrap::_energy;
	this->_attack = FragTrap::_attack;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name")
{
	std::cout << "DiamondTrap constructor called\n";
	this->_name = name;
	this->_health = FragTrap::_attack;
	this->_energy = ScavTrap::_energy;
	this->_attack = FragTrap::_attack;
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
