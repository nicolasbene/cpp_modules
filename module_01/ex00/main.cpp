/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 19:10:07 by nibenoit          #+#    #+#             */
/*   Updated: 2023/08/06 19:48:47 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie *z1 = newZombie("Zombie1");
	randomChump("Zombie2");
	randomChump("Zombie3");
	Zombie *z4 = newZombie("Zombie4");
	Zombie *z5 = newZombie("Zombie5");
	Zombie *z6 = newZombie("Zombie6");

	delete z1;
	delete z4;
	delete z5;
	delete z6;
	return 0;
}
