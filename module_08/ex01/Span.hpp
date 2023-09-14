/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:18:35 by nibenoit          #+#    #+#             */
/*   Updated: 2023/09/14 18:52:32 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>

class	Span
{
	private:
		std::vector<int>	_v;
		unsigned int		_size;
		unsigned int		_index;
	public:
		Span();
		Span(unsigned int n);
		Span(Span const &instance);
		virtual ~Span();

		Span&	operator=(Span const &instance);

		void	addNumber(int n);
		int		shortestSpan(void);
		int		longestSpan(void);
		void	insert(std::vector<int>::iterator begin, std::vector<int>::iterator end);

		class	FullSpanException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Span is full");
				}
		};

		class	NotEnoughSpaceException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Not enough space in Span");
				}
				
		};
};

#endif