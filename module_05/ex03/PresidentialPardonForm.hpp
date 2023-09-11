/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 10:47:57 by nibenoit          #+#    #+#             */
/*   Updated: 2023/09/11 10:49:05 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include "AForm.hpp"

class	PresidentialPardonForm : public AForm
{
	private:
		std::string		_target;

	public:
		// Constructors
		PresidentialPardonForm();
		PresidentialPardonForm(std::string const &target);
		PresidentialPardonForm(PresidentialPardonForm const &instance);
		
		// Destructor
		virtual ~PresidentialPardonForm();

		// Operators
		PresidentialPardonForm&	operator=(PresidentialPardonForm const &rhs);

		// Getters
		std::string	getTarget(void) const;
		
		// Methods
		void	execute(Bureaucrat const &executor) const;
};

#endif