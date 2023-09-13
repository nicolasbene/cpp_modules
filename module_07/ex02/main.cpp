/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:32:17 by nibenoit          #+#    #+#             */
/*   Updated: 2023/09/13 15:39:43 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
#include <limits>
#include <cstdlib>

// int main()
// {	
// 	Array<int> a(5);
// 	Array<int> b(5);

// 	for (int i = 0; i < 5; i++)
// 	{
// 		a[i] = i;
// 		b[i] = i + 5;
// 	}

// 	std::cout << "a: ";
// 	for (int i = 0; i < 5; i++)
// 		std::cout << a[i] << " ";
// 	std::cout << std::endl;

// 	std::cout << "b: ";
// 	for (int i = 0; i < 5; i++)
// 		std::cout << b[i] << " ";
// 	std::cout << std::endl;
	
// 	std::cout << "a = b" << std::endl;
// 	a = b;
// 	std::cout << "a: ";
// 	for (int i = 0; i < 5; i++)
// 		std::cout << a[i] << " ";
// 	std::cout << std::endl;

// 	std::cout << "b: ";
// 	for (int i = 0; i < 5; i++)
// 		std::cout << b[i] << " ";
// 	std::cout << std::endl;

// 	std::cout << "a[0] = 42" << std::endl;
// 	a[0] = 42;
// 	std::cout << "a: ";
// 	for (int i = 0; i < 5; i++)
// 		std::cout << a[i] << " ";
// 	std::cout << std::endl;

// 	std::cout << "b: ";
// 	for (int i = 0; i < 5; i++)
// 		std::cout << b[i] << " ";
// 	std::cout << std::endl;

	
// }


#define MAX_VAL 750

int main(int, char**)
{
    int*        mirror = new int[MAX_VAL];
    Array<int>  numbers(MAX_VAL);

    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++) {
        const int   value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    {
        Array<int>  tmp = numbers;
        Array<int>  test(tmp);
    }
    for (int i = 0; i < MAX_VAL; i++) {
        if (mirror[i] != numbers[i]) {
            std::cerr << "Didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    std::cout << "All values are the same for Array<int> and int[]\n";
    {
        Array<int>    copy;

        copy = numbers;
        copy[0] = numbers[0] + 10;
        std::cout << "copy[0] = " << copy[0] << ", numbers[0] = " << numbers[0] << std::endl;
    }
    try {
        std::cout << "Trying to access index -2 of array:\n";
        numbers[-2] = 0;
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    try {
        std::cout << "Trying to access index LEN of array:\n";
        numbers[MAX_VAL] = 0;
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    
    delete [] mirror;
    return 0;
}
