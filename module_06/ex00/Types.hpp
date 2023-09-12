/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Types.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:09:46 by nibenoit          #+#    #+#             */
/*   Updated: 2023/09/12 12:36:28 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_HPP
# define TYPES_HPP

# include <iostream>
# include <string>
# include <limits>
# include <cstdlib>

enum e_type
{
	TYPE_NOTHING,
	TYPE_NAN,
	TYPE_INT,
	TYPE_FLOAT,
	TYPE_DOUBLE,
	TYPE_INF_MINUS,
	TYPE_INF_PLUS
};

class	Types
{
	private:
		char	_char_value;
		int		_int_value;
		float	_float_value;
		double	_double_value;
		int		_type;

	public:
		// Constructors
		Types(void);
		Types(Types const &instance);
		Types(std::string value);

		// Destructor
		~Types(void);

		// Operators
		Types&	operator=(Types const &rhs);

		// Exceptions
		class NonNumericValueException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		// Getters and Setters
		char	getCharValue(void) const;
		int		getIntValue(void) const;
		float	getFloatValue(void) const;
		double	getDoubleValue(void) const;
		int		getType(void) const;

};

std::ostream	&operator<<(std::ostream &stream, Types const &types);
#endif