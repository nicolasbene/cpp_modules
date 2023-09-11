/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:40:07 by nibenoit          #+#    #+#             */
/*   Updated: 2023/09/11 11:06:55 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
private:
	std::string const	_name;
	int					_grade;
	
	static int const	_max_grade = 1;
	static int const	_min_grade = 150;

public:
	Bureaucrat(void);
	~Bureaucrat(void);
	Bureaucrat(std::string name, int grade);
	Bureaucrat(Bureaucrat const &src);
	
	Bureaucrat &operator=(Bureaucrat const &rhs);

	//Getters
	std::string const	&getName(void) const;
	int					getGrade(void) const;

	//Exceptions
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

	//Methods
	void	incrementGrade(void);
	void	decrementGrade(void);
	void	signForm(AForm& form);
	void	executeForm(AForm const &form) const;
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &rhs);

#endif