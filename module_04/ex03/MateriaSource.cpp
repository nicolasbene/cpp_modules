/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 04:54:56 by jferrer-          #+#    #+#             */
/*   Updated: 2023/09/05 14:27:15 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		_slots[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& copy)
{
	for (int i = 0; i < 4; i++)
	{
		if (_slots[i])
			delete(_slots[i]);
		if (copy._slots[i])
			_slots[i] = copy._slots[i];
		else
			_slots[i] = NULL;
	}
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
		if (_slots[i])
			delete(_slots[i]);
}

MateriaSource & MateriaSource::operator=(const MateriaSource& op)
{
	if (this == &op)
		return (*this);
	for (int i = 0; i < 4; i++)
	{
		if (_slots[i])
			delete(_slots[i]);
		if (op._slots[i])
			_slots[i] = op._slots[i];
		else
			_slots[i] = NULL;
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria* newmateria)
{
	for (int i = 0; i < 4; i++)
	{
		if (_slots[i] == NULL)
		{
			_slots[i] = newmateria;
			break;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
		if (_slots[i] != NULL && _slots[i]->getType() == type)
			return (_slots[i]->clone());
	return (0);
}
