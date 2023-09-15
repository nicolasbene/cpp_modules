/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:24:55 by nibenoit          #+#    #+#             */
/*   Updated: 2023/09/14 18:51:45 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _size(0), _index(0) {}

Span::Span(unsigned int n) : _size(n), _index(0) {}

Span::Span(Span const &instance) : _size(instance._size), _index(instance._index)
{
	this->_v = instance._v;
}

Span::~Span() {}

Span&	Span::operator=(Span const &instance)
{
	this->_size = instance._size;
	this->_index = instance._index;
	this->_v = instance._v;
	return (*this);
}

void	Span::addNumber(int n)
{
	if (this->_index < this->_size)
	{
		this->_v.push_back(n);
		this->_index++;
	}
	else
		throw Span::FullSpanException();
}

int	Span::shortestSpan(void)
{
	if (this->_index < 2)
		throw Span::NotEnoughSpaceException();
	std::sort(this->_v.begin(), this->_v.end());
	return (this->_v[1] - this->_v[0]);
}

int	Span::longestSpan(void)
{
	if (this->_index < 2)
		throw Span::NotEnoughSpaceException();
	std::sort(this->_v.begin(), this->_v.end());
	return (this->_v[this->_index - 1] - this->_v[0]);
}


void	Span::insert(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (this->_index + std::distance(begin, end) <= this->_size)
	{
		this->_v.insert(this->_v.end(), begin, end);
		this->_index += std::distance(begin, end);
	}
	else
		throw Span::NotEnoughSpaceException();
}
