/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:33:25 by nibenoit          #+#    #+#             */
/*   Updated: 2023/09/13 10:48:00 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

template <typename T>
void	iter(T *array, size_t len, void (*f)(T const &elem))
{
	for (size_t i = 0; i < len; i++)
		f(array[i]);
}

template <typename T>
void	print(T const &elem)
{
	std::cout << elem << " ";
}

#endif