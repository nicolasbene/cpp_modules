/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:18:26 by nibenoit          #+#    #+#             */
/*   Updated: 2023/09/06 15:18:28 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_H
# define CHARACTER_H

# include <iostream>
# include "ICharacter.h"

class	Character: public ICharacter
{
	public:
		Character(void);
		Character(const Character& character);
		~Character(void);
		Character&	operator=(const Character& character);

		Character(std::string name);

		void				equip(AMateria* m);
		void				unequip(int idx);
		void 				use(int idx, ICharacter& target);
		const std::string&	getName() const;
		AMateria*			getItem(int idx) const;

	private:
		static const int	NB_ITEMS = 4;

		std::string	_name;
		AMateria	*_inventory[NB_ITEMS];
};

#endif
