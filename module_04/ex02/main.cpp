/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 17:10:33 by nibenoit          #+#    #+#             */
/*   Updated: 2023/08/24 16:29:52 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int	main(void)
{
	Animal*	animals[100];
	for (int i=0; i < 100; i++) {
		if (i % 2)
			animals[i] = new Cat();
		else
			animals[i] = new Dog();
	}
	for (int i=0; i < 100; i++)
		delete animals[i];

	std::cout << std::endl;
	
	std::cout << "----------Test copy & switch idea-----------" << std::endl;

    Dog dog1("Philibert");

    dog1.setIdea(0, "Croquette");
    std::cout << "Philibert idea: " << dog1.getIdea(0) << std::endl;
    Dog dog2(dog1);
    std::cout << "Philibert idea: " << dog1.getIdea(0) << std::endl;
    std::cout << "Copy idea: " << dog2.getIdea(0) << std::endl;
    dog2.setIdea(0, "os");
    std::cout << "Philibert idea: " << dog1.getIdea(0) << std::endl;
    std::cout << "Copy idea: " << dog2.getIdea(0) << std::endl;
	return (0);
}
