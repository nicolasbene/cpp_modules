/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 00:43:01 by jferrer-          #+#    #+#             */
/*   Updated: 2023/09/05 17:31:32 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>
#include "ICharacter.hpp"

class AMateria
{
	private:
		std::string _type;

	public:
		AMateria(const AMateria&);
		AMateria& operator=(const AMateria&);
		AMateria(std::string const & type);
		virtual ~AMateria();

		std::string const & getType() const;

		virtual	AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif
