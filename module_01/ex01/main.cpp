/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 19:10:07 by nibenoit          #+#    #+#             */
/*   Updated: 2023/08/06 20:09:28 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	int		N;
	Zombie *zombies;
	
	N = 8;
	zombies = zombieHorde(N, "Ria");
	for (int i=0; i < N; i++)
		zombies[i].announce();
	delete[] zombies;
	return 0;
}
