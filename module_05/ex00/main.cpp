/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:33:14 by nibenoit          #+#    #+#             */
/*   Updated: 2023/09/07 14:14:43 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


int	main(void)
{
	{
		std::cout << "Test constuctors, increment, decrement and << operator:\n";
		Bureaucrat	b1 = Bureaucrat("Nico", 1);
		std::cout << b1 << std::endl;
		b1.decrementGrade();
		b1.decrementGrade();
		Bureaucrat	b2 = b1;
		b1.decrementGrade();
		b2.incrementGrade();
		Bureaucrat	b3(b1);
		b3.incrementGrade();
		std::cout << b1 << std::endl;
		std::cout << Bureaucrat() << std::endl;
		std::cout << "(Clone 1): " << b2 << std::endl;
		std::cout << "(Clone 2): "<< b3 << std::endl;
	}
	{
		std::cout << "\nTest errors on constructors and increment, decrement:\n";
		try {
			Bureaucrat b1("Nico", 0);
			std::cout << "This text should not appear !\n";
		} catch (Bureaucrat::GradeTooHighException& e) {
			std::cout << e.what() << std::endl;
		}
		try {
			Bureaucrat b1("Nico", 151);
			std::cout << "This text should not appear !\n";
		} catch (Bureaucrat::GradeTooLowException& e) {
			std::cout << e.what() << std::endl;
		}
		try {
			Bureaucrat b1("Nico", 1);
			std::cout << "This text should appear !\n";
			b1.incrementGrade();
			std::cout << "This text should not appear !\n";
		} catch (Bureaucrat::GradeTooHighException& e) {
			std::cout << e.what() << std::endl;
		}
		try {
			Bureaucrat b1("Nico", 150);
			std::cout << "This text should appear !\n";
			b1.decrementGrade();
			std::cout << "This text should not appear !\n";
		} catch (Bureaucrat::GradeTooLowException& e) {
			std::cout << e.what() << std::endl;
		}
	}
	return (0);
}