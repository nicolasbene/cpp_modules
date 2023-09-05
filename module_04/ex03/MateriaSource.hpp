/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 04:54:58 by jferrer-          #+#    #+#             */
/*   Updated: 2023/09/05 14:24:15 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include <iostream>
#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
	private:
		AMateria*	slots[4];

	public:
		MateriaSource();
		virtual ~MateriaSource();
		MateriaSource(const MateriaSource&);
		MateriaSource &operator=(const MateriaSource&);

		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
};

#endif
