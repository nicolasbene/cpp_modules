/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 19:23:21 by nibenoit          #+#    #+#             */
/*   Updated: 2023/08/17 19:25:10 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void): ClapTrap()
{
	std::cout << "FragTrap default contructor called\n";
	_health = 100;
	_energy = 100;
	_attack = 30;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	std::cout << "FragTrap contructor called\n";
	_health = 100;
	_energy = 100;
	_attack = 30;
}

FragTrap::FragTrap(const FragTrap& fragtrap): ClapTrap(fragtrap)
{
	std::cout << "FragTrap clone contructor called\n";
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor called\n";
}

FragTrap&	FragTrap::operator=(const FragTrap& fragtrap)
{
	ClapTrap::operator=(fragtrap);
	std::cout << "FragTrap copy assignment operator called\n";
	return *this;
}

void	FragTrap::highFivesGuys(void) const
{
	std::cout << "FragTrap let's do a high five guys !\n";
}
