/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:09:02 by nibenoit          #+#    #+#             */
/*   Updated: 2023/09/23 18:01:59 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe () {}

PmergeMe::PmergeMe (const PmergeMe &instance)
{
		*this = instance;
}

PmergeMe::~PmergeMe () {}

PmergeMe & PmergeMe::operator=(const PmergeMe &rhs)
{
        (void)rhs;
        return(*this);
}
