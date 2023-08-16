/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:05:31 by nibenoit          #+#    #+#             */
/*   Updated: 2023/08/16 17:46:14 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int     main(void)
{
        ClapTrap        ct1("Caro");
        ClapTrap        ct2("Seb");
        ClapTrap        ct3("Cam");

        ct1.attack("Seb");
        ct2.takeDamage(ct1.getAttack());
        ct1.attack("Cam");
        ct3.takeDamage(ct1.getAttack());
        ct3.attack("Seb");
        ct2.takeDamage(ct3.getAttack());
        ct2.beRepaired(10);
        return 0;
}