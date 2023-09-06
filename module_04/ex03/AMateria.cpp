/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:17:53 by nibenoit          #+#    #+#             */
/*   Updated: 2023/09/06 15:17:58 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.h"

AMateria::AMateria(const std::string& type)
{
	_type = type;
}

const std::string&	AMateria::getType(void) const
{
	return _type;
}

void	AMateria::use(ICharacter& target)
{
	std::cout << "* do nothing to " << target.getName() << " *" << std::endl;
}
