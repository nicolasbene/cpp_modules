/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:18:57 by nibenoit          #+#    #+#             */
/*   Updated: 2023/09/06 15:18:58 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_H
# define ICHARACTER_H

# include <string>
# include "AMateria.h"

class AMateria;

class	ICharacter
{
	public:
		virtual ~ICharacter() {}
		virtual void				equip(AMateria* m) = 0;
		virtual void				unequip(int idx) = 0;
		virtual void 				use(int idx, ICharacter& target) = 0;
		virtual const std::string&	getName() const = 0;
};

#endif
