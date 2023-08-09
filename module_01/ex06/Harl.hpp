/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:08:02 by nibenoit          #+#    #+#             */
/*   Updated: 2023/08/09 16:22:24 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

class Harl
{
	public:
		void	complain(std::string level);
	
	private:
		typedef void (Harl::*funcPTR)(void);
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
};

#endif