/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:19:22 by nibenoit          #+#    #+#             */
/*   Updated: 2023/09/06 15:19:23 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIA_SOURCE_H
# define MATERIA_SOURCE_H

# include "IMateriaSource.h"

class	MateriaSource: public IMateriaSource
{
	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource& materiaSource);
		~MateriaSource(void);
		MateriaSource&	operator=(const MateriaSource& materiaSource);

		void		learnMateria(AMateria* materia);
		AMateria*	createMateria(const std::string& type);

		AMateria*	getMateria(int i) const;

	private:
		static const int	NB_MATERIAS = 4;

		AMateria*	_materias[NB_MATERIAS];

};


#endif
