/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:07:10 by nibenoit          #+#    #+#             */
/*   Updated: 2023/09/11 11:26:21 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(): _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {}

AForm::~AForm() {}

AForm::AForm(std::string const &name, int gradeToSign, int gradeToExecute): _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(AForm const &src): _name(src._name), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{
	_signed = src.getSigned();
}

AForm&	AForm::operator=(AForm const &rhs)
{
	_signed = rhs.getSigned();
	return (*this);
}

std::ostream&	operator<<(std::ostream& stream, const AForm& form)
{
	stream << "Form " << form.getName() << " is ";
	if (form.getSigned())
		stream << "signed";
	else
		stream << "not signed";
	stream << " and requires a grade " << form.getGradeToSign() << " to be signed and a grade " << form.getGradeToExecute() << " to be executed.";
	return stream;
}

// Exceptions
const char *AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
};

const char *AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
};

const char *AForm::FormNotSignedException::what(void) const throw()
{
	return ("Form not signed");
};

//getters
bool	AForm::getSigned(void) const
{
	return _signed;
}

int	AForm::getGradeToSign(void) const
{
	return _gradeToSign;
}

int	AForm::getGradeToExecute(void) const
{
	return _gradeToExecute;
}

std::string	&AForm::getName(void) const
{
	return (std::string&)_name;
}

void	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw AForm::GradeTooLowException();
	_signed = true;
}

void	AForm::execute(Bureaucrat const &executor) const
{
	if (!_signed)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > _gradeToExecute)
		throw AForm::GradeTooLowException();
}