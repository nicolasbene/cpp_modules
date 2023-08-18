/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:05:31 by nibenoit          #+#    #+#             */
/*   Updated: 2023/08/18 16:56:37 by nibenoit         ###   ########.fr       */
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
	dt1.attack("Caroline");
	return 0;
}
