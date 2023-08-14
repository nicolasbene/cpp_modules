/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 14:46:41 by nibenoit          #+#    #+#             */
/*   Updated: 2023/08/14 17:26:25 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called\n";
	_bits = 0;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called\n";
	_bits = value << _fractional_bits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called\n";
	_bits = roundf(value * (1 << _fractional_bits));
}

Fixed::Fixed(const Fixed& fixed)
{
	std::cout << "Copy constructor called\n";
	_bits = fixed._bits;
}

Fixed&	Fixed::operator=(const Fixed& fixed)
{
	std::cout << "Copy assignment operator called\n";
	_bits = fixed._bits;
	return *this;
}

std::ostream&	operator<<(std::ostream& stream, const Fixed& fixed)
{
	stream << fixed.toFloat();
	return stream;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called\n";
}

int	Fixed::getRawBits(void) const
{
	std::cout << "Member function getRawBits called\n";
	return _bits;
}

void	Fixed::setRawBits(const int raw)
{
	std::cout << "Member function setRawBits called\n";
	_bits = raw;
}

int	Fixed::toInt(void) const
{
	return _bits >> _fractional_bits;
}

float	Fixed::toFloat(void) const
{
	return (float)_bits / (float)(1 << _fractional_bits);
}
