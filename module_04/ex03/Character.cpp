/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferrer- <jferrer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 22:38:27 by jferrer-          #+#    #+#             */
/*   Updated: 2022/09/20 22:38:38 by jferrer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(const std::string& name): _name(name)
{
	for (int i = 0; i < 4; i++)
		_slots[i] = NULL;
}

Character::Character(const Character& copy): _name(copy.getName())
{
	for (int i = 0; i < 4; i++)
    {
        if (copy._slots[i])
            _slots[i] = copy._slots[i]->clone();
        else
            _slots[i] = NULL;
    }
}

Character::Character(const Character& character)
{
	int	i;

	i = 0;
	while (i < NB_ITEMS) {
		if (character.getItem(i))
			_inventory[i] = character.getItem(i)->clone();
		else
			_inventory[i] = NULL;
		i++;
	}
}



Character::~Character()
{
	for (int i = 0; i < 4; i++)
		if (_slots[i])
			delete(_slots[i]);
}

Character & Character::operator=(const Character& op)
{
	if (this == &op)
		return (*this);
	_name = op.getName();
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

std::string const & Character::getName() const
{
	return (_name);
}

void	Character::equip(AMateria* materia)
{
	for (int i = 0; i < 4; i++)
	{
		if (_slots[i] == NULL)
		{
			_slots[i] = materia;
			break;
		}
	}
}

void	Character::unequip(int index)
{
	if (_slots[index] && index >= 0 && index < 4)
		_slots[index] = NULL;
}

void	Character::use(int index, ICharacter& target)
{
	if (index >= 0 && index < 4 && _slots[index])
		_slots[index]->use(target);
}

AMateria*	Character::getItem(int index) const
{
	if (index < 0 || index >= 4)
		return NULL;
	return _slots[index];
}
