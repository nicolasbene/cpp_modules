/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:29:27 by nibenoit          #+#    #+#             */
/*   Updated: 2023/08/24 16:37:35 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class	Animal
{
	public:
		Animal(void);
		Animal(const Animal& animal);
		virtual	~Animal(void);
		Animal&	operator=(const Animal& animal);

		virtual void	makeSound(void) const;
		std::string		getType(void) const;
		
	protected:
		std::string	_type;

};

#endif