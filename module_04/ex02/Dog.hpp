/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 19:00:28 by nibenoit          #+#    #+#             */
/*   Updated: 2023/08/24 16:17:18 by nibenoit         ###   ########.fr       */
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
		Dog(std::string name);
		~Dog(void);
		Dog& operator=(const Dog& dog);
		
		void		makeSound(void) const;
		Brain*		getBrain(void) const;
		
		void		setIdea(int i, std::string idea);
		std::string	getIdea(int i) const;

	private:
		std::string	_name;
		Brain*		_brain;
		std::string	_ideas[100];

};

#endif