/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:18:40 by nibenoit          #+#    #+#             */
/*   Updated: 2023/09/06 15:18:41 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_H
# define CURE_H

# include <iostream>
# include "AMateria.h"

class	Cure: public AMateria
{
	public:
		Cure(void);
		Cure(const Cure& cure);
		~Cure(void);
		Cure&	operator=(const Cure& cure);

		void		use(ICharacter& target);
		AMateria*	clone(void) const;
};

#endif
