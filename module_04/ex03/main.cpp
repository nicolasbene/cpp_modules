/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 00:43:06 by jferrer-          #+#    #+#             */
/*   Updated: 2023/09/05 19:02:11 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AMateria.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;
	}
	{
		std::cout << "Test a bit everything:\n";
		AMateria*		tmp;
		IMateriaSource*	source = new MateriaSource();
		ICharacter*		c1 = new Character("Arthur");
		ICharacter* 	c2 = new Character("Victor");

		source->learnMateria(new Cure());
		source->learnMateria(new Ice());
		tmp = source->createMateria("ice");
		c1->equip(tmp);
		tmp = source->createMateria("cure");
		c1->equip(tmp);
		std::cout << c1->getName() << " uses materia 1 on " << c2->getName() << std::endl;
		c1->use(0, *c2);
		std::cout << c1->getName() << " uses materia 2 on " << c2->getName() << std::endl;
		c1->use(1, *c2);
		delete c1;
		delete c2;
		delete source;
	}
	// {
	// 	std::cout << "\nTest character deep copy and leaks:\n";
	// 	Character	c1 = Character("Arthur");
	// 	Character	c2 = Character(c1);
	// 	Character	c3 = Character("Victor");

	// 	c1.equip(new Ice());
	// 	c2.equip(new Cure());
	// 	c2 = Character(c1);
	// 	c2.equip(new Cure());
	// 	std::cout << c1.getName() << " uses materia 2 on " << c3.getName() << std::endl;
	// 	c1.use(1, c3);
	// 	std::cout << std::endl;
	// 	std::cout << c2.getName() << " uses materia 2 on " << c3.getName() << std::endl;
	// 	c2.use(1, c3);
	// }
	{
		std::cout << "\nTest unequiped materia:\n";
		AMateria	*ice = new Ice();
		Character	c1 = Character("Arthur");
		Character	c2 = Character("Victor");

		c1.equip(ice);
		c1.unequip(0);
		std::cout << c1.getName() << " uses materia 1 on " << c2.getName() << std::endl;
		c1.use(0, c2);
		std::cout << std::endl;
		c1.equip(ice);
		std::cout << c1.getName() << " uses materia 1 on " << c2.getName() << std::endl;
		c1.use(0, c2);
	}
	return 0;
}
