/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:57:28 by nibenoit          #+#    #+#             */
/*   Updated: 2023/08/01 16:22:32 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void    print_touper(std::string s)
{
    for (int i=0; s[i]; i++)
        std::cout << (char) toupper(s[i]);
}

int main(int ac, char **av)
{
    if (ac > 1)
    {
        for (int i=1; av[i]; i++)
            print_touper(av[i]);
    }
    else
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    std::cout << std::endl;
}