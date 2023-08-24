/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 14:50:06 by nibenoit          #+#    #+#             */
/*   Updated: 2023/08/24 15:07:14 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain default constructor\n";
}

Brain::Brain(const Brain& brain)
{
	std::cout << "Brain clone constructor\n";
	*this = brain;
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor\n";
}

Brain& Brain::operator=(const Brain& brain)
{
	std::cout << "Brain copy assignement operator\n";
	for (int i=0; i < 100; i++)
		_ideas[i] = brain._ideas[i];
	return *this;
}

std::string	Brain::getIdea(int i) const
{
	return _ideas[i];
}

void	Brain::setIdea(int i, std::string idea)
{
	_ideas[i] = idea;
}