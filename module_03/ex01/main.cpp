/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:05:31 by nibenoit          #+#    #+#             */
/*   Updated: 2023/08/16 19:32:48 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap	ct1("Arthur");
	ClapTrap	ct2("Victor");
	ScavTrap	st1("Seb");
	ScavTrap	st2(st1);
	ScavTrap	st3("Thomas");

	ct1.attack("Victor");
	ct2.takeDamage(ct1.getAttack());
	ct1.attack("Thomas");
	st3.takeDamage(ct1.getAttack());
	st3.attack("Victor");
	ct2.takeDamage(st3.getAttack());
	ct2.beRepaired(10);
	st2.attack("Victor");
	ct2.takeDamage(st2.getAttack());
	return 0;
}