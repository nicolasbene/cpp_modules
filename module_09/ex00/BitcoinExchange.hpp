/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:35:11 by nibenoit          #+#    #+#             */
/*   Updated: 2023/09/20 16:50:20 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <iomanip>
#include <string>
#include <cstdlib>

class BitcoinExchange
{
	private:
		std::map<std::string , float> _database;
	public:
		BitcoinExchange ();
		BitcoinExchange (const BitcoinExchange &a);
		~BitcoinExchange ();
		BitcoinExchange & operator = (const BitcoinExchange &a);

		void	ReadBase(void);
		void	PrintMap(std::map<std::string, float> mymap);
		void	ReadInput(std::string file);
		int		Parsing(int year, int month, int day, std::string raate, float rate, std::string line);
		void	PrintOutput(std::string inputdate, float bitcoins);

		//exceptions
		class InvalidFormatException : public std::exception
		{
		public:
			InvalidFormatException(const char* message) : message_(message) {}

			virtual const char* what() const throw()
			{
				return message_;
			}

		private:
			const char* message_;
		};

		class InvalidRateException : public std::exception
		{
			public:
				InvalidRateException(const char* message) : message_(message) {}

				virtual const char* what() const throw()
				{
					return message_;
				}

			private:
				const char* message_;
		};
};

#endif