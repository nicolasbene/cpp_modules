/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:54:28 by nibenoit          #+#    #+#             */
/*   Updated: 2023/09/11 11:04:23 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("default"), _grade(150) {}

Bureaucrat::~Bureaucrat(void) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	if (grade < Bureaucrat::_max_grade)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > Bureaucrat::_min_grade)
		throw Bureaucrat::GradeTooLowException();
}

// Exceptions
const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
};

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
};

Bureaucrat::Bureaucrat(Bureaucrat const &src) : _name(src._name), _grade(src._grade) {}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &rhs)
{
	this->_grade = rhs._grade;
	return (*this);
}

std::ostream&	operator<<(std::ostream& stream, const Bureaucrat& rhs)
{
	stream << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return stream;
}

std::string const	&Bureaucrat::getName(void) const
{
	return _name;
}

int	Bureaucrat::getGrade(void) const
{ 
	return _grade;
}

void	Bureaucrat::incrementGrade(void)
{
	if (_grade == _max_grade)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void	Bureaucrat::decrementGrade(void)
{
	if (_grade == _min_grade)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

void	Bureaucrat::signForm(AForm& form)
{
	try {
		form.beSigned(*this);
		std::cout << _name << " signed the form " << form.getName() << std::endl;
	} catch (AForm::GradeTooLowException& e) {
		std::cout << _name << " couldn't sign the form " << form.getName() << std::endl;
	} catch (AForm::GradeTooHighException& e) {
		std::cout << _name << " couldn't sign the form " << form.getName() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const &form) const
{
	try {
		form.execute(*this);
		std::cout << _name << " executed the form " << form.getName() << std::endl;
	} catch (AForm::GradeTooLowException& e) {
		std::cout << _name << " couldn't execute the form " << form.getName() << std::endl;
	} catch (AForm::GradeTooHighException& e) {
		std::cout << _name << " couldn't execute the form " << form.getName() << std::endl;
	} catch (AForm::FormNotSignedException& e) {
		std::cout << _name << " couldn't execute the form " << form.getName() << std::endl;
	}
}
