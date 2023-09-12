/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:30:42 by nibenoit          #+#    #+#             */
/*   Updated: 2023/09/12 17:32:05 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>
# include <string>

class	Data
{
	public:
		// Constructors
		Data(void);
		Data(Data const &data);
		Data(std::string name);

		// Destructor
		~Data(void);

		// Operators
		Data&	operator=(Data const &data);

		// Getters and Setters
		std::string	getName(void) const;

	private:
		std::string	_name;

};

#endif