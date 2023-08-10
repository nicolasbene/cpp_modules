/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 18:02:30 by nibenoit          #+#    #+#             */
/*   Updated: 2023/08/03 10:59:58 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
        _first_name = "";
        _last_name = "";
        _nickname = "";
        _phone_number = "";
        _secret = "";
}

Contact::Contact(std::string fn, std::string ln, std::string nn, std::string pn, std::string secret)
{
        _first_name = fn;
        _last_name = ln;
        _nickname = nn;
        _phone_number = pn;
        _secret = secret;
}


void	Contact::display_infos(void)
{
	std::cout << "Contact Informations" << std::endl;
	std::cout << "First name\t: " << _first_name << std::endl;
	std::cout << "Last name\t: " << _last_name << std::endl;
	std::cout << "Nickname\t: " << _nickname << std::endl;
	std::cout << "Phone number\t: " << _phone_number << std::endl;
	std::cout << "Darkest secret\t: " << _secret << "\n\n";
}

std::string	Contact::getFirstName()
{
	return _first_name;
}

std::string	Contact::getLastName()
{
	return _last_name;
}

std::string	Contact::getNickname()
{
	return _nickname;
}

Contact::~Contact() {}
