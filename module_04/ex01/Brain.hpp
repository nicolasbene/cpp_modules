/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 12:30:28 by nibenoit          #+#    #+#             */
/*   Updated: 2023/08/24 14:49:59 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class	Brain
{
	public:
		Brain(void);
		Brain(const Brain& brain);
		~Brain(void);
		Brain&	operator=(const Brain& brain);

		void		setIdea(int i, std::string idea);
		std::string	getIdea(int i) const;

	private:
		std::string	_ideas[100];
};

#endif