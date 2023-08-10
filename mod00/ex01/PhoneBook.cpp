/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 17:59:43 by nibenoit          #+#    #+#             */
/*   Updated: 2023/08/05 18:46:38 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
        _nb_contact = 0;
}

void	PhoneBook::add_contact(Contact new_contact)
{
	if (_nb_contact == 8)
	{
		for (int i=1; i < _nb_contact; i++)
			_contacts[i - 1] = _contacts[i];
		_contacts[_nb_contact - 1] = new_contact;
	}
	else
		_contacts[_nb_contact++] = new_contact;
}

static bool	is_valid_name(std::string name)
{
	for (int i=0; name[i]; i++)
		if (name[i] != '-' && name[i] != ' ' && !isalpha(name[i]))
			return (false);
	return (true);
}

static bool	is_valid_number(std::string number)
{
	  for (int i=0; number[i]; i++)
		  if (!isdigit(number[i]))
			  return (false);
	  return (true);
}

static bool is_empty(std::string answer)
{
	for (int i=0; answer[i]; i++)
		if (!isspace(answer[i]))
			return (false);
	return (true);
}

static std::string	read_prompt(std::string prompt, bool (*validator)(std::string), std::string error_msg)
{
	std::string answer;

	while (true) {
		std::cout << prompt;
		if (!std::getline(std::cin, answer)) {
            if (std::cin.eof())
                return "";
        }
		if (is_empty(answer))
			std::cout << "Your input cannot be an empty string.\n";
		else if (validator && !validator(answer))
			std::cout << error_msg << "\n";
		else
			break;
	}
	return (answer);
}

void	PhoneBook::add_contact(void)
{
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	secret;

	std::cout << "New Contact Creation\n";
	first_name = read_prompt("First Name\t: ", &is_valid_name, "Please enter a valid name (only letters, - and space)");
	if (first_name == "")
		return ;
	last_name = read_prompt("Last name\t: ", &is_valid_name, "Please enter a valid name (only letters, - and space)");
	if (last_name == "")
		return ;
	nickname = read_prompt("Nickname\t: ", &is_valid_name, "Please enter a valid name (only letters, - and space)");
	if (nickname == "")
		return ;
	phone_number = read_prompt("Phone number\t: ", &is_valid_number, "Please enter a valid phone number (only digits)");
	if (phone_number == "")
		return ;
	secret = read_prompt("Darkest secret\t: ", NULL, "An error occured with your input please try again");
	if (secret == "")
		return ;
	this->add_contact(Contact(first_name, last_name, nickname, phone_number, secret));
	std::cout << "Contact successfully added\n\n";
}

static std::string	int_to_string(int i)
{
	std::ostringstream ss;

	ss << i;
	return (ss.str());
}

static std::string	align_word(std::string word, int len)
{
	int			i;
	int			w_len;
	std::string	aligned;

	w_len = word.length();
	i = 0;
	while (i + w_len < len) {
		aligned += ' ';
		i++;
	}
	aligned += word;
	aligned = aligned.substr(0, len);
	if (w_len > len)
		aligned[len - 1] = '.';
	return aligned;
}

static void	one_line_format(std::string a, std::string b, std::string c, std::string d)
{
	std::cout << "|" << align_word(a, 10);
	std::cout << "|" << align_word(b, 10);
	std::cout << "|" << align_word(c, 10);
	std::cout << "|" << align_word(d, 10) << "|\n";
}

void	PhoneBook::display_contacts(void)
{
	int			id;
	std::string	input;

	std::cout << "---------------------------------------------\n" ;
	one_line_format("Index", "First name", "Last name", "Nickname");
	std::cout << "---------------------------------------------\n";
	for (int i=0; i < _nb_contact; i++) {
		one_line_format(int_to_string(i + 1), _contacts[i].getFirstName(), _contacts[i].getLastName(), _contacts[i].getNickname());
		std::cout << "---------------------------------------------\n";
	}
	std::cout << "\nPlease enter the id of the contact you want to see: ";
	if (!std::getline(std::cin, input))
		exit(1);
	id = 0;
	if (input.length() == 1)
		id = input[0] - '0';
	if (!isdigit(input[0]) || id < 1 || id > _nb_contact)
		std::cout << "Error: this is not a valid contact id\n\n";
	else
		_contacts[id - 1].display_infos();
}

void	PhoneBook::search(void)
{
	this->display_contacts();
}


// Definition du destructeur
PhoneBook::~PhoneBook() {}