/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 10:40:20 by nibenoit          #+#    #+#             */
/*   Updated: 2023/08/16 18:19:12 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP

# include <iostream>
# include <climits>

class ClapTrap
{
	public:
		ClapTrap(void);
		ClapTrap(const ClapTrap& claptrap);
		ClapTrap(std::string name);
		~ClapTrap(void);

		ClapTrap& operator=(const ClapTrap& claptrap);

		void			attack(const std::string& target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
		unsigned int	getHealth(void) const;
        unsigned int	getEnergy(void) const;
        unsigned int	getAttack(void) const;
        std::string		getName(void) const;
		
	private:
		std::string		_name;
		unsigned int	_health;
		unsigned int	_energy;
		unsigned int	_attack;
};

#endif