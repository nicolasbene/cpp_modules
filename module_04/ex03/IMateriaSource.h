/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:19:03 by nibenoit          #+#    #+#             */
/*   Updated: 2023/09/06 15:19:04 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIA_SOURCE_H
# define IMATERIA_SOURCE_H

# include <string>
# include "AMateria.h"

class	IMateriaSource
{
	public:
		virtual ~IMateriaSource() {}
		virtual void		learnMateria(AMateria* materia) = 0;
		virtual AMateria*	createMateria(const std::string& type) = 0;
};

#endif
