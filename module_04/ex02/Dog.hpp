/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 19:00:28 by nibenoit          #+#    #+#             */
/*   Updated: 2023/08/24 16:52:48 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class	Dog : public Animal
{
	public:
		Dog(void);
		Dog(const Dog& dog);
		~Dog(void);
		Dog&	operator=(const Dog& dog);

		void	makeSound(void) const;
		Brain*	getBrain(void) const;

	private:
		Brain*	_brain;
};

#endif