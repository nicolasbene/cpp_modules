/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:05:31 by nibenoit          #+#    #+#             */
/*   Updated: 2023/08/17 18:54:13 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap	ct1("Caro");
	ClapTrap	ct2("Seb");
	ScavTrap	st1("Antho");
	ScavTrap	st2(st1);
	ScavTrap	st3("Cam");

	ct1.attack("Seb");
	ct2.takeDamage(ct1.getAttack());
	ct1.attack("Cam");
	st3.takeDamage(ct1.getAttack());
	st3.attack("Seb");
	ct2.takeDamage(st3.getAttack());
	ct2.beRepaired(10);
	st1.guardGate();
	st2.guardGate();
	return 0;
}