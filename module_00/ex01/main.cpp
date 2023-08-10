/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:40:04 by nibenoit          #+#    #+#             */
/*   Updated: 2023/08/04 13:53:00 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

int main() {
    bool over = false;
    std::string line;
    PhoneBook phonebook;

    phonebook = PhoneBook();
    do {
        std::cout << "PhoneBook>";
        std::getline(std::cin, line);
        if (std::cin.eof()) {
            std::cout << "\nExiting...\n";
            return 1;
        } else if (line == "ADD")
            phonebook.add_contact();
        else if (line == "SEARCH")
            phonebook.search();
        else if (line == "EXIT") {
            std::cout << "Sorry to see you leave ;(\n";
            over = true;
        } else
            std::cout << "Wrong arguments, only accepted : ADD, SEARCH, EXIT" << '\n';
    } while (!over);

    return 0;
}