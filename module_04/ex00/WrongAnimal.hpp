/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 19:04:42 by nibenoit          #+#    #+#             */
/*   Updated: 2023/08/23 19:15:21 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

# include <iostream>

class	WrongAnimal
{
	public:
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal& WrongAnimal);
		~WrongAnimal(void);
		
		WrongAnimal&	operator=(const WrongAnimal& WrongAnimal);

		void			makeSound(void) const;
		std::string		getType(void) const;

		protected:
			std::string	_type;

};

#endif