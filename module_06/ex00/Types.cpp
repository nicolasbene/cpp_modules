/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Types.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:28:50 by nibenoit          #+#    #+#             */
/*   Updated: 2023/09/12 14:30:41 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Types.hpp"

#include <limits>

static e_type	get_type(std::string value)
{
	int	i;

	if (value == "nan" || value == "nanf")
		return TYPE_NAN;
	if (value == "+inf" || value == "+inff")
		return TYPE_INF_PLUS;
	if (value == "-inf" || value == "-inff")
		return TYPE_INF_MINUS;
	i = 0;
	if (value[i] == '-')
		i++;
	while (std::isdigit(value[i]))
		i++;
	if (value[i] == '.') {
		int	j = i + 1;
		while (std::isdigit(value[j]))
			j++;
		if (value[j] == 'f' && value[j + 1] == 0)
			return TYPE_FLOAT;
		if (value[j] == 0 && j != i + 1)
			return TYPE_DOUBLE;
		return TYPE_NOTHING;
	}
	if (value.size() > 0 && value[i] == 0) {
		if (value.size() > 11 || atof(value.c_str()) > std::numeric_limits<int>::max() || atof(value.c_str()) < std::numeric_limits<int>::min())
			return TYPE_DOUBLE;
		return TYPE_INT;
	}
	return TYPE_NOTHING;
}

Types::Types(void)
{
	_char_value = 0;
	_int_value = 0;
	_float_value = 0;
	_double_value = 0;
	_type = TYPE_INT;
}

Types::Types(const Types& types)
{
	_char_value = types.getCharValue();
	_int_value = types.getIntValue();
	_float_value = types.getFloatValue();
	_double_value = types.getDoubleValue();
	_type = types.getType();
}

Types::Types(std::string value)
{
	_type = get_type(value);
	_char_value = 0;
	switch (_type) {
		case TYPE_INT:
			_int_value = std::atoi(value.c_str());
			_float_value = static_cast<float>(_int_value);
			_double_value = static_cast<double>(_int_value);
			_char_value = static_cast<char>(_int_value);
			break;
		case TYPE_FLOAT:
			_float_value = std::atof(value.c_str());
			_double_value = static_cast<double>(_float_value);
			_int_value = static_cast<int>(_float_value);
			_char_value = static_cast<char>(_float_value);
			break;
		case TYPE_DOUBLE:
			_double_value = std::atof(value.c_str());
			_float_value = static_cast<float>(_double_value);
			_int_value = static_cast<int>(_double_value);
			_char_value = static_cast<char>(_double_value);
			break;
		case TYPE_INF_MINUS:
			_float_value = std::numeric_limits<float>::infinity() * -1;
			_double_value = std::numeric_limits<double>::infinity() * -1;
			break;
		case TYPE_INF_PLUS:
			_float_value = std::numeric_limits<float>::infinity();
			_double_value = std::numeric_limits<double>::infinity();
			break;
		case TYPE_NAN:
			_float_value = std::numeric_limits<float>::quiet_NaN();
			_double_value = std::numeric_limits<double>::quiet_NaN();
			break;
		case TYPE_NOTHING:
			throw NonNumericValueException();
			break;
	}
}

Types::~Types(void) {}

Types&	Types::operator=(const Types& types)
{
	_char_value = types.getCharValue();
	_int_value = types.getIntValue();
	_float_value = types.getFloatValue();
	_double_value = types.getDoubleValue();
	_type = types.getType();
	return *this;
}

char	Types::getCharValue(void) const
{
	return _char_value;
}

int	Types::getIntValue(void) const
{
	return _int_value;
}

float	Types::getFloatValue(void) const
{
	return _float_value;
}

double	Types::getDoubleValue(void) const
{
	return _double_value;
}

int	Types::getType(void) const
{
	return _type;
}

//Exceptions
const char*	Types::NonNumericValueException::what() const throw()
{
	return "Non numeric value";
}

std::ostream&	operator<<(std::ostream& stream, Types const &types)
{
	int	type;

	type = types.getType();
	if (type == TYPE_NAN || type == TYPE_INF_MINUS || type == TYPE_INF_PLUS || types.getIntValue() < 0 || types.getIntValue() > 127)
		stream << "char: impossible" << std::endl;
	else if (!std::isprint(types.getCharValue()))
		stream << "char: Non displayable" << std::endl;
	else
		stream << "char: '" << types.getCharValue() << "'" << std::endl;
	if (type == TYPE_NAN || type == TYPE_INF_MINUS || type == TYPE_INF_PLUS)
		stream << "int: impossible" << std::endl;
	else if ((type == TYPE_FLOAT || type == TYPE_DOUBLE) && (types.getDoubleValue() > std::numeric_limits<int>::max() || types.getDoubleValue() < std::numeric_limits<int>::min()))
		stream << "int: impossible" << std::endl;
	else
		stream << "int: " << types.getIntValue() << std::endl;
	stream << "float: " << types.getFloatValue();
	if (types.getIntValue() == types.getFloatValue() && types.getIntValue() < 1000000)
		stream << ".0";
	stream << "f" << std::endl;
	stream << "double: " << types.getDoubleValue();
	if (types.getIntValue() == types.getDoubleValue() && types.getIntValue() < 1000000)
		stream << ".0";
	stream << std::endl;
	return stream;
}
