/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:18:52 by nibenoit          #+#    #+#             */
/*   Updated: 2023/09/06 15:18:53 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_H
# define ICE_H

# include <iostream>
# include "AMateria.h"

class	Ice: public AMateria
{
	public:
		Ice(void);
		Ice(const Ice& ice);
		~Ice(void);
		Ice&	operator=(const Ice& ice);

		void		use(ICharacter& target);
		AMateria*	clone(void) const;
};

#endif
