/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 02:35:36 by jferrer-          #+#    #+#             */
/*   Updated: 2023/09/05 19:00:02 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character: public ICharacter
{
	private:
		std::string	_name;
		AMateria*	_slots[4];

	public:
		Character(const std::string&);
		Character(const Character&);
		virtual ~Character();
		Character &operator=(const Character& op);

		std::string const &getName() const;
		void	equip(AMateria* materia);
		void	unequip(int index);
		void	use(int index, ICharacter& target);
};

#endif
