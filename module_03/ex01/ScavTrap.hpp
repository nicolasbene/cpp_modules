/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 18:14:07 by nibenoit          #+#    #+#             */
/*   Updated: 2023/08/16 19:30:37 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class	ScavTrap: public ClapTrap
{
	public:
		ScavTrap(void);
		ScavTrap(const ScavTrap& scavtrap);
		ScavTrap(std::string name);
		~ScavTrap(void);

		ScavTrap&	operator=(const ScavTrap& scavtrap);

		void	guardGate(void);
};

#endif