/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:09:13 by nibenoit          #+#    #+#             */
/*   Updated: 2023/09/25 15:00:01 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template <typename T, typename S, typename V>

void    algo(int ac, T &container, S &conta, V &contb, char choice, bool flag, int tmp)
{
	//              Time
	struct timeval start, end;
	long sec, micro;

	gettimeofday(&start, NULL);
	for (size_t i = 0; i < container.size(); i++)
	{
		if (container[i].first > container[i].second)
			std::swap(container[i].first, container[i].second);
	}

	for (size_t i = 0; i < container.size(); i++)
		conta.push_back(container[i].first);

	for (size_t i = 0; i < container.size(); i++)
		contb.push_back(container[i].second);

	std::sort(conta.begin(), conta.end());

	for (size_t i = 0; i < contb.size(); i++)
		conta.insert(std::lower_bound(conta.begin(), conta.end(), contb[i]), contb[i]);
	if (flag)
		conta.insert(std::lower_bound(conta.begin(), conta.end(), tmp), tmp);

	std::cout << "\nAfter  : ";

	for (size_t i = 0; i < conta.size(); i++)
		std::cout << conta[i] << " ";

	gettimeofday(&end, NULL);
	sec = end.tv_sec - start.tv_sec;
	micro = end.tv_usec - start.tv_usec;
	long diff = (sec / 1000000) + (micro);
	if (choice == 'v')
		std::cout << "\nTime to process a range of " << ac << " elements with std::vector : " << diff  << " us" << "\n";
	if (choice == 'd')
		std::cout << "\nTime to process a range of " << ac << " elements with std::deque : " << diff  << " us" << "\n";
}

void    checkInput(char *av1, char *av2)
{
	if (std::atoi(av1) < 0 || std::atoi(av2) < 0)
	{
		std::cerr << "Invalid Input: Number Less Than 0\n";
		exit(0);
	}
}

static bool	is_valid_number(const char* s)
{
	size_t	i;

	i = 0;
	while (s && s[i] && (s[i] == ' ' || s[i] == '\t'))
		i++;
	while (s && s[i] && std::isdigit(s[i]))
		i++;
	return i < 11 && s[i] == 0;
}

int main(int ac, char *av[])
{
	bool	flag = false;
	int		tmp = 0;
	
	if (ac < 2)
	{
		std::cerr << "Invalid Input: No Arguments\n";
		return 0;
	}
	for (int i = 1; i < ac; i++)
	{
		if (!is_valid_number(av[i]))
		{
			std::cerr << "Invalid Input: Not A Number\n";
			return 0;
		}
	}
	ac -= 1;
	if (ac % 2 != 0)
	{
		flag = true;
		tmp = std::atoi(av[ac]);
		if (tmp < 0)
		{
			std::cerr << "Invalid Input: Number Negative\n";
			return 0;
		}
	}

	std::cout << "Before : "; 
	if (ac < 6)
	{
		for (int i = 1; i <= ac; i++)
			std::cout << av[i] << " ";
	}
	else
	{
		for (int i = 1; i < 6; i++)
			std::cout << av[i] << " ";
		std::cout << "[...]";
	}


	//vector

	std::vector<std::pair<int, int> > vec;
	for (int i = 1; i < ac; i+=2)
	{
		if (isdigit(*av[i]))
		{
			checkInput(av[i], av[i + 1]);    
			vec.push_back(std::make_pair(std::atoi(av[i]), std::atoi(av[i + 1])));
		}
	}
	std::vector<int> vec_a, vec_b;
	algo(ac, vec, vec_a, vec_b, 'v', flag, tmp);

	//deque

	std::deque<std::pair<int, int> > dec;
	for (int i = 1; i < ac; i+=2)
	{
		if (isdigit(*av[i]))
		{
			checkInput(av[i], av[i + 1]);    
			dec.push_back(std::make_pair(std::atoi(av[i]), std::atoi(av[i + 1])));
		}
	}
	std::deque<int> dec_a, dec_b;
	algo(ac, dec, dec_a, dec_b, 'd', flag, tmp);

	return 0;
}