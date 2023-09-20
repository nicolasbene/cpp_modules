/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:35:11 by nibenoit          #+#    #+#             */
/*   Updated: 2023/09/20 22:37:39 by nibenoit         ###   ########.fr       */
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
		class BitcoinExchangeException : public std::exception
		{
		public:
			BitcoinExchangeException(const char* message) : message_(message) {}

			virtual const char* what() const throw()
			{
				return message_;
			}

		private:
			const char* message_;
		};

		class InvalidFileException : public BitcoinExchangeException
		{
		public:
			InvalidFileException(const char* message) : BitcoinExchangeException(message) {}
		};

		class InvalidDateFormatException : public BitcoinExchangeException
		{
		public:
			InvalidDateFormatException(const char* message) : BitcoinExchangeException(message) {}
		};

		class InvalidRateFormatException : public BitcoinExchangeException
		{
		public:
			InvalidRateFormatException(const char* message) : BitcoinExchangeException(message) {}
		};

		class InvalidPipeException : public BitcoinExchangeException
		{
		public:
			InvalidPipeException(const char* message) : BitcoinExchangeException(message) {}
		};
};

#endif