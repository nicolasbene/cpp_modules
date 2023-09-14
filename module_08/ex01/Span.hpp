/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:18:35 by nibenoit          #+#    #+#             */
/*   Updated: 2023/09/14 16:38:55 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>

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
};

#endif