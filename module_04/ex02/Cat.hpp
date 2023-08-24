/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:51:54 by nibenoit          #+#    #+#             */
/*   Updated: 2023/08/24 16:52:44 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class	Cat : public Animal
{
	public:
		Cat(void);
		Cat(const Cat& cat);
		~Cat(void);
		Cat&	operator=(const Cat& cat);

		void	makeSound(void) const;
		Brain*	getBrain(void) const;

	private:
		Brain*	_brain;
};


#endif