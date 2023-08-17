/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:05:31 by nibenoit          #+#    #+#             */
/*   Updated: 2023/08/17 19:28:05 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	ClapTrap	ct1("Seb");
	ClapTrap	ct2("Max");
	ClapTrap	ct3("Caro");
	ScavTrap	st1("Antho");
	ScavTrap	st2(st1);
	FragTrap	ft1("Cam");
	FragTrap	ft2(ft1);

	ct1.attack("Max");
	ct2.takeDamage(ct1.getAttack());
	ct1.attack("Caro");
	ct3.takeDamage(ct1.getAttack());
	ct3.attack("Max");
	ct2.takeDamage(ct3.getAttack());
	ct2.beRepaired(10);
	st1.guardGate();
	st2.guardGate();
	ft1.attack("Arthur");
	ct1.takeDamage(ft1.getAttack());
	ft1.highFivesGuys();
	return 0;
}
