/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 14:45:00 by nibenoit          #+#    #+#             */
/*   Updated: 2023/08/14 17:26:20 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

#include <iostream>

class Fixed
{
	public:
		Fixed(void);
		Fixed(const Fixed& fixed);
		~Fixed(void);
		Fixed & operator=(const Fixed& fixed);
		int		getRawBits(void) const;
		void	setRawBits(const int raw);

	private:
		int					_bits;
		static const int	fractional_bits = 8;
};

#endif
