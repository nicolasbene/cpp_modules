/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 18:14:07 by nibenoit          #+#    #+#             */
/*   Updated: 2023/08/18 17:55:28 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class	ScavTrap: virtual public ClapTrap
{
	public:
		ScavTrap(void);
		ScavTrap(const ScavTrap& scavtrap);
		~ScavTrap(void);
		ScavTrap&	operator=(const ScavTrap& scavtrap);

		ScavTrap(std::string name);

		void	guardGate(void);
		void	attack(const std::string& target);
};

#endif