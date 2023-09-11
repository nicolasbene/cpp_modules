/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 11:45:07 by nibenoit          #+#    #+#             */
/*   Updated: 2023/09/11 11:50:47 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "AForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"

class	Intern
{
	public:
		Intern(void);
		Intern(Intern const &src);
		~Intern(void);
		
		Intern&	operator=(Intern const &src);

		//Method
		AForm	*makeForm(std::string const &name, std::string const &target);

};

#endif