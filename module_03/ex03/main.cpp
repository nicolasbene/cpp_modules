/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:05:31 by nibenoit          #+#    #+#             */
/*   Updated: 2023/08/23 15:53:32 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap	dt1("Sebastien");
	DiamondTrap	dt2(dt1);
	DiamondTrap	dt3;

	dt3 = dt2;
	dt1.whoAmI();
	dt1.attack("boby");
	return 0;
}
