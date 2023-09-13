/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:54:26 by nibenoit          #+#    #+#             */
/*   Updated: 2023/09/13 15:32:30 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T>

class Array
{
	private:
		T		*_array;
		int		_size;
	public:
		Array(void)
		{
			_array = NULL;
			_size = 0;
		}
		
		Array(unsigned int n)
		{
			_array = new T[n];
			_size = n;
		}
		

		Array(const Array<T>& instance)
		{
			_size = instance.getSize();
			_array = new T[_size];
			for (int i = 0; i < _size; i++)
				_array[i] = instance._array[i];
		}
		
		~Array(void)
		{
			if (_array)
				delete [] _array;
		}
		
		Array& operator=(Array const &rhs)
		{
			if (this != &rhs)
			{
				if (_array)
					delete [] _array;
				_size = rhs.getSize();
				_array = new T[_size];
				for (int i = 0; i < _size; i++)
					_array[i] = rhs._array[i];
			}
			return (*this);
		}
		
		T& operator[](int i)
		{
			if (i < 0 || i >= _size)
				throw OutOfLimitsException();
			return (_array[i]);
		}
		
		int getSize(void) const
		{
			return (_size);
		}
		
		class OutOfLimitsException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Out of limits");
				}
		};
};

#endif