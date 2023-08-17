/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 19:45:22 by nibenoit          #+#    #+#             */
/*   Updated: 2023/08/17 19:46:13 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMOND_TRAP_HPP
# define DIAMOND_TRAP_HPP

# include <iostream>
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class	DiamondTrap: public ScavTrap, public FragTrap
{
	public:
		DiamondTrap(void);
		DiamondTrap(const DiamondTrap& diamondtrap);
		~DiamondTrap(void);
		DiamondTrap&	operator=(const DiamondTrap& diamontrap);

		DiamondTrap(std::string name);

		using	ScavTrap::attack;
		void	whoAmI(void);

	private:
		std::string	_name;
};

#endif
