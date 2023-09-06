/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:18:36 by nibenoit          #+#    #+#             */
/*   Updated: 2023/09/06 15:18:37 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.h"

Cure::Cure(void): AMateria("cure") {}

Cure::Cure(const Cure& cure): AMateria(cure) {}

Cure::~Cure(void) {}

Cure&	Cure::operator=(const Cure& cure)
{
	_type = cure.getType();
	return *this;
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

AMateria*	Cure::clone(void) const
{
	return new Cure(*this);
}
