/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 18:01:04 by nibenoit          #+#    #+#             */
/*   Updated: 2023/08/02 17:51:59 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

#include <iostream>

class Contact
{
		private:
				std::string     _first_name;
				std::string     _last_name;
				std::string		_nickname;
				std::string     _secret;
				std::string     _phone_number;

		public:
				Contact();
				Contact(std::string fn, std::string ln, std::string nn, std::string secret, std::string pn);
				~Contact();
				void		display_infos(void);
				std::string	getFirstName();
				std::string	getLastName();
				std::string	getNickname();
};

#endif