/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:07:10 by nibenoit          #+#    #+#             */
/*   Updated: 2023/09/07 18:32:00 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {}

Form::~Form() {}

Form::Form(std::string const &name, int gradeToSign, int gradeToExecute): _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(Form const &src): _name(src._name), _signed(src._signed), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{
	*this = src;
}

// Exceptions
const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
};

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
};

Form&	Form::operator=(Form const &rhs)
{
	this->_signed = rhs._signed;
	return (*this);
}

std::ostream&	operator<<(std::ostream& stream, const Form& form)
{
	stream << "Form " << form.getName() << " is ";
	if (form.getSigned())
		stream << "signed";
	else
		stream << "not signed";
	stream << " and requires a grade " << form.getGradeToSign() << " to be signed and a grade " << form.getGradeToExecute() << " to be executed.";
	return stream;
}

bool	Form::getSigned(void) const
{
	return _signed;
}

int	Form::getGradeToSign(void) const
{
	return _gradeToSign;
}

int	Form::getGradeToExecute(void) const
{
	return _gradeToExecute;
}

const std::string	&Form::getName(void) const
{
	return _name;
}

void	Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw Form::GradeTooLowException();
	_signed = true;
}
