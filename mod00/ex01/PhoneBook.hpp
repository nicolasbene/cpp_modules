/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 17:29:10 by nibenoit          #+#    #+#             */
/*   Updated: 2023/08/05 18:46:29 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_H
# define PHONE_BOOK_H

# include <iostream>
# include <sstream>
# include <cstdlib>
# include "Contact.hpp"

# define MAX_CONTACT 8

class PhoneBook
{
	private:
		int _nb_contact;
		Contact	_contacts[MAX_CONTACT];
		
	public:
		PhoneBook(); // Constructeur
		~PhoneBook(); // Destructeur
		void    add_contact();
		void	add_contact(Contact new_contact);
		void	search();
		void	display_contacts();
};

#endif