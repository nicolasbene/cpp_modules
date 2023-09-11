/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 11:47:04 by nibenoit          #+#    #+#             */
/*   Updated: 2023/09/11 12:30:39 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void) {}

Intern::Intern(Intern const &instance)
{ 
	*this = instance;
}

Intern::~Intern(void) {}

Intern&	Intern::operator=(Intern const &rhs)
{
	(void)rhs;
	return (*this);
}

AForm* Intern::makeForm(std::string const &name, std::string const &target)
{
	int	i = 0;
	AForm*	form;
	std::string	forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	while (i < 3)
	{
		if (name == forms[i])
			break ;
		i++;
	}
	switch (i) {
		case 0:
			form = new ShrubberyCreationForm(target);
			break;
		case 1:
			form = new RobotomyRequestForm(target);
			break;
		case 2:
			form = new PresidentialPardonForm(target);
			break;
		default:
			form = NULL;
			std::cout << "This type of form does not exist !" << std::endl;
	}
	if (form)
		std::cout << "Intern creates " << form->getName() << std::endl;
	return (form);
}