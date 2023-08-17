/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:05:59 by nibenoit          #+#    #+#             */
/*   Updated: 2023/08/17 19:52:40 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	std::cout << "ClapTrap default constructor called\n";
	_name = "John";
	_health = 10;
	_energy = 10;
	_attack = 0;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap constructor called\n";
	_name = name;
	_health = 10;
	_energy = 10;
	_attack = 0;
}

ClapTrap::ClapTrap(const ClapTrap& claptrap)
{
	std::cout << "ClapTrap clone constructor called\n";
	*this = claptrap;
}


ClapTrap&	ClapTrap::operator=(const ClapTrap& claptrap)
{
	std::cout << "ClapTrap copy assginment operator called\n";
	_name = claptrap.getName();
	_health = claptrap.getHealth();
	_energy = claptrap.getEnergy();
	_attack = claptrap.getAttack();
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor default called\n";
}

unsigned int	ClapTrap::getHealth(void) const
{
		return _health;
}

unsigned int	ClapTrap::getEnergy(void) const
{
		return _energy;
}

unsigned int	ClapTrap::getAttack(void) const
{
		return _attack;
}

std::string		ClapTrap::getName(void) const
{
		return _name;
}

void	ClapTrap::attack(const std::string& target)
{
	if (_energy == 0 || _health == 0)
		std::cout << "ClapTrap " << _name << " cannot attack because it does not have enough energy !\n";
	else
	{
		_energy--;
		std::cout << "ClapTrap " << _name << " attack " << target << ", causing " << _attack << " points of damage\n";
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > _health)
		_health = 0;
	else
	{
		_health -= amount;
		std::cout << "ClapTrap " << _name << " take " << amount << " damage\n";
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_energy == 0 || _health == 0)
		std::cout << "ClapTrap " << _name << " cannot attack because it does not have enough energy !\n";
	else
	{
		_energy--;
		if (UINT_MAX - _health < amount)
			_health = UINT_MAX;
		else
			_health += amount;
		std::cout << "ClapTrap " << _name << " gain " << amount << " hit points\n";
	}
}