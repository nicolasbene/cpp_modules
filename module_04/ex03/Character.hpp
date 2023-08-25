/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 16:11:23 by nibenoit          #+#    #+#             */
/*   Updated: 2023/08/25 17:33:04 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <iostream>
#include "ICharacter.hpp"

class	Character : public ICharacter
{
	public:
		Character(void);
		Character(const Character& src);
		~Character(void);

		Character&	operator=(const Character& src);

		Character(std::string name);

		void				equip(AMateria* m);
		void				unequip(int idx);
		void 				use(int idx, ICharacter& target);
		const std::string&	getName() const;
	
	private:
		std::string	_name;
		AMateria*	_inventory[4];

};

#endif