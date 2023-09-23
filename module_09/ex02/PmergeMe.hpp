/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:09:09 by nibenoit          #+#    #+#             */
/*   Updated: 2023/09/23 18:01:10 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>
#include <sys/time.h>
#include <unistd.h> 



class PmergeMe
{
    private:
        // your private members here
    public:
        PmergeMe ();
        PmergeMe (const PmergeMe &a);
        ~PmergeMe ();
        PmergeMe & operator = (const PmergeMe &a);
};

#endif