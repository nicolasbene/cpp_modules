/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 10:58:57 by nibenoit          #+#    #+#             */
/*   Updated: 2023/09/11 10:59:07 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	{
		std::cout << "Test case Shrubbery Creation form, all working:" << std::endl;
		ShrubberyCreationForm	form("home");
		Bureaucrat				b("Granny", 100);

		b.signForm(form);
		b.executeForm(form);
		std::cout << std::endl;
	}
	{
		std::cout << "Test case Roboto Request form, all working:" << std::endl;
		RobotomyRequestForm	form("Theo");
		Bureaucrat			b("R2D2", 45);

		b.signForm(form);
		b.executeForm(form);
		std::cout << std::endl;
	}
	{
		std::cout << "Test case Presidential Pardon form, all working:" << std::endl;
		PresidentialPardonForm form("Victor");
		Bureaucrat	b("Arthur", 5);

		b.signForm(form);
		b.executeForm(form);
		std::cout << std::endl;
	}
	{
		std::cout << "Test case permission to sign but not to execute" << std::endl;
		PresidentialPardonForm form("Maro");
		Bureaucrat	b("Nathan", 15);

		b.signForm(form);
		b.executeForm(form);
		std::cout << std::endl;
	}
	{
		std::cout << "Test case no enough permissions at all" << std::endl;
		PresidentialPardonForm form("Paul");
		Bureaucrat	b("Nassim", 30);

		b.signForm(form);
		b.executeForm(form);
	}

	return (0);
}
