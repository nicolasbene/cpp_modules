/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:18:16 by nibenoit          #+#    #+#             */
/*   Updated: 2023/09/06 15:18:18 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_H
# define AMATERIA_H

# include <iostream>
# include "ICharacter.h"

class ICharacter;

class	AMateria
{
	public:
		AMateria(const std::string& type);

		virtual ~AMateria(void) {};

		const std::string&	getType(void) const;

		virtual	AMateria*	clone(void) const = 0;
		virtual void		use(ICharacter& target);

	protected:
		std::string	_type;
};

#endif
