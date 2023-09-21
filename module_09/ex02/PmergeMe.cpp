/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:09:02 by nibenoit          #+#    #+#             */
/*   Updated: 2023/09/21 18:12:05 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(): _list_vec(), _list_deque(), _time_vec(), _time_deque() {}


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

PmergeMe::PmergeMe(char** numbers): _list_vec(), _list_deque(), _time_vec(), _time_deque()
{
	size_t		i;
	size_t		number;

	i = 0;
	while (numbers && numbers[i]) {
		if (!is_valid_number(numbers[i])) {
			std::cerr << "Error: invalid number in list: '" << numbers[i] << "'\n";
			exit(1);
		}
		number = std::atol(numbers[i]);
		_list_vec.push_back(number);
		_list_deque.push_back(number);
		i++;
	}
}

PmergeMe::PmergeMe(const PmergeMe& other)
: _list_vec(other._list_vec), _list_deque(other._list_deque),
_time_vec(other._time_vec), _time_deque(other._time_deque) {}

PmergeMe&	PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other) {
		_list_vec = other._list_vec;
		_list_deque = other._list_deque;
		_time_vec = other._time_vec;
		_time_deque = other._time_deque;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

bool	PmergeMe::_is_sorted_vec()
{
	for (size_t i=0; i < _list_vec.size() - 1; i++) {
		if (_list_vec[i] > _list_vec[i + 1])
			return false;
	}
	return true;
}

bool	PmergeMe::_is_sorted_deque()
{
	for (size_t i=0; i < _list_deque.size() - 1; i++) {
		if (_list_deque[i] > _list_deque[i + 1])
			return false;
	}
	return true;
}

static void	print_list(std::vector<size_t> list)
{
	if (list.size() < 16) {
		for (size_t i=0; i < list.size(); i++)
			std::cout << list[i] << " ";
		std::cout << std::endl;
	} else {
		for (size_t i=0; i < 5; i++)
			std::cout << list[i] << " ";
		std::cout << "[...] ";
		for (size_t i=list.size() - 5; i < list.size(); i++)
			std::cout << list[i] << " ";
		std::cout << std::endl;
	}
}

static double	timediff(struct timeval end, struct timeval start)
{
	double	diff;

	diff = ((end.tv_sec - start.tv_sec) * 1000000 + ((double)(end.tv_usec - start.tv_usec)));
	return diff;
}

void	PmergeMe::_sort_vec(size_t start, size_t end)
{
	size_t	len = end - start;
	if (len < INSERT_TRESHOLD) {
		_insertion_sort_vec(start, end);
	} else {
		size_t	middle_len = len / 2;
		_sort_vec(start, start + middle_len);
		_sort_vec(start + middle_len + 1, end);
		_merge_vec(start, start + middle_len, end);
	}
}

void	PmergeMe::_merge_vec(size_t start, size_t middle, size_t end)
{
	size_t	i = start, j = middle + 1;

	std::vector<size_t>	sorted;
	while (i <= middle || j <= end) {
		if (j > end || (i <= middle && _list_vec[i] < _list_vec[j]))
			sorted.push_back(_list_vec[i++]);
		else
			sorted.push_back(_list_vec[j++]);
	}
	i = 0;
	while (i < sorted.size()) {
		_list_vec[i + start] = sorted[i];
		i++;
	}
}

void	PmergeMe::_insertion_sort_vec(size_t start, size_t end)
{
	size_t	i = start;

	while (i < end) {
		if (_list_vec[i] > _list_vec[i + 1]) {
			_list_vec[i] ^= _list_vec[i + 1];
			_list_vec[i + 1] ^= _list_vec[i];
			_list_vec[i] ^= _list_vec[i + 1];
			if (i > start)
				i--;
			else
				i++;
		} else {
			i++;
		}
	}
}

void	PmergeMe::_sort_deque(size_t start, size_t end)
{
	size_t	len = end - start;
	if (len < INSERT_TRESHOLD) {
		_insertion_sort_deque(start, end);
	} else {
		size_t	middle_len = len / 2;
		_sort_deque(start, start + middle_len);
		_sort_deque(start + middle_len + 1, end);
		_merge_deque(start, start + middle_len, end);
	}
}

void	PmergeMe::_merge_deque(size_t start, size_t middle, size_t end)
{
	size_t	i = start, j = middle + 1;

	std::deque<size_t>	sorted;
	while (i <= middle || j <= end) {
		if (j > end || (i <= middle && _list_deque[i] < _list_deque[j]))
			sorted.push_back(_list_deque[i++]);
		else
			sorted.push_back(_list_deque[j++]);
	}
	i = 0;
	while (i < sorted.size()) {
		_list_deque[i + start] = sorted[i];
		i++;
	}
}

void	PmergeMe::_insertion_sort_deque(size_t start, size_t end)
{
	size_t	i = start;

	while (i < end) {
		if (_list_deque[i] > _list_deque[i + 1]) {
			_list_deque[i] ^= _list_deque[i + 1];
			_list_deque[i + 1] ^= _list_deque[i];
			_list_deque[i] ^= _list_deque[i + 1];
			if (i > start)
				i--;
			else
				i++;
		} else {
			i++;
		}
	}
}


void	PmergeMe::sort()
{
	struct timeval	start, end;

	std::cout << "Before: ";
	print_list(_list_vec);
	gettimeofday(&start, NULL);
	_sort_vec(0, _list_vec.size() - 1);
	gettimeofday(&end, NULL);
	if (!_is_sorted_vec())
		std::cerr << "Error: the list is not sorted properly !!" << std::endl;
	std::cout << "After:  ";
	print_list(_list_vec);
	std::cout << "Time to process a range of " << _list_vec.size() << " elements with std::vector : ";
	std::cout << timediff(end, start) << " µs" << std::endl;
	gettimeofday(&start, NULL);
	_sort_deque(0, _list_deque.size() - 1);
	gettimeofday(&end, NULL);
	if (!_is_sorted_deque())
		std::cerr << "Error: the list is not sorted properly !!" << std::endl;
	std::cout << "Time to process a range of " << _list_vec.size() << " elements with std::deque : ";
	std::cout << timediff(end, start) << " µs" << std::endl;
}
