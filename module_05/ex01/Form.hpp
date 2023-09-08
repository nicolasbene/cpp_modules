/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 14:31:00 by nibenoit          #+#    #+#             */
/*   Updated: 2023/09/08 15:48:35 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string	_name;
		bool		_signed;
		int			_gradeToSign;
		int			_gradeToExecute;

	public:
		Form();
		virtual ~Form();
		Form(std::string const &name, int gradeToSign, int gradeToExecute);
		Form(Form const &src);

		Form&	operator=(Form const &rhs);

		const std::string	&getName(void) const;
		bool				getSigned(void) const;
		int					getGradeToSign(void) const;
		int					getGradeToExecute(void) const;

		void				beSigned(Bureaucrat const &bureaucrat);

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
};

std::ostream&	operator<<(std::ostream &out, Form const &src);

#endif