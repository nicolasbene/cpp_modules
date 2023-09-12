/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:31:25 by nibenoit          #+#    #+#             */
/*   Updated: 2023/09/12 17:32:18 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(void)
{
	_name = "";
}

Data::Data(Data const &data)
{
	_name = data.getName();
}

Data::Data(std::string name)
{
	_name = name;
}

Data::~Data(void) {}

Data&	Data::operator=(Data const &data)
{
	_name = data.getName();
	return *this;
}

std::string	Data::getName(void) const
{
	return _name;
}
