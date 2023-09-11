/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 10:58:57 by nibenoit          #+#    #+#             */
/*   Updated: 2023/09/11 12:31:23 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	{
		Intern	intern;
		AForm*	form;

		form = intern.makeForm("shrubbery creation", "Bender");
		if (form)
			delete form;
	}
	{
		Intern	intern;
		AForm*	form;

		form = intern.makeForm("robotomy request", "Bender");
		if (form)
			delete form;
	}
	{
		Intern	intern;
		AForm*	form;

		form = intern.makeForm("presidential pardon", "Bender");
		if (form)
			delete form;
	}
	{
		Intern	intern;
		AForm*	form;

		form = intern.makeForm("some random form", "Bender");
		if (form)
			delete form;
	}
	return (0);
}