/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 00:43:04 by jferrer-          #+#    #+#             */
/*   Updated: 2023/09/05 17:37:27 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(const AMateria& copy): _type(copy._type) {}

AMateria::AMateria(std::string const & type): _type(type) {}

AMateria::~AMateria() {}

AMateria & AMateria::operator=(const AMateria& op)
{
	if (this == &op)
		return (*this);
	//this->type = op.type;
	return (*this);
}

std::string const & AMateria::getType() const
{
	return _type;
}

void AMateria::use(ICharacter& target)
{
	(void)target;
}
