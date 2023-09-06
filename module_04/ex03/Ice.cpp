/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:18:46 by nibenoit          #+#    #+#             */
/*   Updated: 2023/09/06 15:18:47 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.h"

Ice::Ice(void): AMateria("ice") {}

Ice::Ice(const Ice& ice): AMateria(ice) {}

Ice::~Ice(void) {}

Ice&	Ice::operator=(const Ice& ice)
{
	_type = ice.getType();
	return *this;
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria*	Ice::clone(void) const
{
	return new Ice(*this);
}
