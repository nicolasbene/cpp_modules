/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:44:37 by nibenoit          #+#    #+#             */
/*   Updated: 2023/09/11 10:31:03 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <fstream>
# include "AForm.hpp"

class	ShrubberyCreationForm : public AForm
{
	private:
		std::string		_target;

	public:
		// Constructors
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string const &target);
		ShrubberyCreationForm(ShrubberyCreationForm const &instance);
		
		// Destructor
		virtual ~ShrubberyCreationForm();

		// Operators
		ShrubberyCreationForm&	operator=(ShrubberyCreationForm const &rhs);

		// Getters
		std::string	getTarget(void) const;
		
		// Methods
		void	execute(Bureaucrat const &executor) const;
};


#endif