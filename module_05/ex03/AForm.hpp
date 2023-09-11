/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 14:31:00 by nibenoit          #+#    #+#             */
/*   Updated: 2023/09/11 11:24:19 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		std::string	_name;
		bool		_signed;
		int			_gradeToSign;
		int			_gradeToExecute;

	public:
		AForm();
		virtual ~AForm() = 0;
		AForm(std::string const &name, int gradeToSign, int gradeToExecute);
		AForm(AForm const &src);

		AForm&	operator=(AForm const &rhs);

		std::string	&getName(void) const;
		bool		getSigned(void) const;
		int			getGradeToSign(void) const;
		int			getGradeToExecute(void) const;

		// exceptions
		class GradeTooLowException : public std::exception
		{
		public:
			virtual const char *what() const throw();
		};

		class GradeTooHighException : public std::exception
		{
		public:
			virtual const char *what() const throw();
		};

		class FormNotSignedException : public std::exception
		{
		public:
			virtual const char* what() const throw();
		};
		
		// member functions
		virtual void	beSigned(Bureaucrat const &bureaucrat);
		virtual void	execute(Bureaucrat const &executor) const;
};

std::ostream&	operator<<(std::ostream &out, AForm const &src);

#endif