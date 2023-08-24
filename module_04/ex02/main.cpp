/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 17:10:33 by nibenoit          #+#    #+#             */
/*   Updated: 2023/08/24 17:10:21 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int	main(void)
{
	{
		const Animal*	dog = new Dog();
		const Animal*	cat = new Cat();

		delete dog;
		delete cat;
		std::cout << std::endl;
	}
	{
		Dog	dog;
		Dog	dog2(dog);

		dog.getBrain()->setIdea(0, "manger des chips au cacahuete");
		dog2.getBrain()->setIdea(0, "lire un livre");
		std::cout << dog.getBrain()->getIdea(0) << std::endl;
		std::cout << dog2.getBrain()->getIdea(0) << std::endl;
	}
	{
		std::cout << std::endl;
		Cat	cat;
		Cat	cat2(cat);
	
		cat.getBrain()->setIdea(0, "jouer au foot");
		cat2.getBrain()->setIdea(0, "rapper sur de la drill");
		std::cout << cat.getBrain()->getIdea(0) << std::endl;
		std::cout << cat2.getBrain()->getIdea(0) << std::endl;
	}
	return (0);
}
