/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 10:43:55 by nibenoit          #+#    #+#             */
/*   Updated: 2023/09/11 10:44:47 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <cstdlib>
# include "AForm.hpp"

class	RobotomyRequestForm : public AForm
{
	private:
		std::string		_target;

	public:
		// Constructors
		RobotomyRequestForm();
		RobotomyRequestForm(std::string const &target);
		RobotomyRequestForm(RobotomyRequestForm const &instance);
		
		// Destructor
		virtual ~RobotomyRequestForm();

		// Operators
		RobotomyRequestForm&	operator=(RobotomyRequestForm const &rhs);

		// Getters
		std::string	getTarget(void) const;
		
		// Methods
		void	execute(Bureaucrat const &executor) const;
};

#endif