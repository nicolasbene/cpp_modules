/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:43:43 by nibenoit          #+#    #+#             */
/*   Updated: 2023/09/20 22:52:57 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange () {}

BitcoinExchange::BitcoinExchange (const BitcoinExchange &instance)
{
	(void)instance;
	*this = instance;
}

BitcoinExchange::~BitcoinExchange () {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
	(void)rhs;
	return (*this);
}

void	BitcoinExchange::ReadBase()
{
	std::ifstream   input;
	std::string     database;

	input.open("./data.csv");
	if (input.fail())
    	throw InvalidFileException("Cannot open base file");
	while (!input.eof())
	{
		input >> database;
		std::string fulldate = database.substr(0,10).erase(4,1).erase(6,1);
		float      rate = 0.0;
		std::stringstream convert;
		convert << database.substr(11);
		convert >> rate;
		_database.insert(std::make_pair(fulldate,rate));
	}
	input.close();
}
int BitcoinExchange::Parsing(int year, int month, int day, std::string raate, float rate, std::string line)
{
    size_t idx = line.find("|");
    if (line[idx + 1] != ' ' || line[idx - 1] != ' ')
        throw InvalidPipeException("Invalid Pipe");

    if (line.substr(4, 1) != "-" && line.substr(7, 1) != "-")
        throw InvalidDateFormatException("Invalid Date Format");

    int count = 0;
    for (size_t i = 0; i < raate.length(); i++)
    {
        if (raate[0] == '.')
            throw InvalidRateFormatException("Invalid Rate Format");
        if (raate[i] == '.')
            count++;
        if (!(isdigit(raate[i])) && raate[i] != '.' && (count == 1 || count == 0))
            throw InvalidRateFormatException("Invalid Rate Format");
    }

    int month_limits[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (year < 2009 || month < 1 || month > 12)
        throw InvalidDateFormatException("Invalid Date Format");
    if (day > month_limits[month - 1] || day < 1)
        throw InvalidDateFormatException("Out of month range");
    if (rate < 0.00 || rate > 1000.00)
        throw InvalidRateFormatException("Rate out of range");
    return 0;
}


void	BitcoinExchange::PrintOutput(std::string inputdate, float bitcoins)
{
	std::map<std::string, float>::iterator itb = this->_database.begin();
	std::map<std::string, float>::iterator ite = this->_database.end();
	bool    flag = false;

	for (; itb != ite; itb++)
	{
		if (itb->first == inputdate)
		{
			flag = true;
			break;
		}
	}
	if (flag == true)
	{
		std::cout << inputdate.insert(4,"-").insert(7,"-") << " => " << bitcoins << " = " <<  std::fixed << std::setprecision(2) << bitcoins * itb->second << "\n";
		flag = false;
	}
	else
	{
		ite = this->_database.lower_bound(inputdate);
		std::cout << inputdate.insert(4,"-").insert(7,"-") << " => " << bitcoins << " = " << std::fixed << std::setprecision(2) << bitcoins * ite->second << "\n";
	}
}

void	BitcoinExchange::ReadInput(std::string file)
{
	std::ifstream input;
	std::string line;

	input.open(file.c_str());
	if (input.fail())
    	throw InvalidFileException("Cannot open input file");

	while (!input.eof())
	{
		std::string fulldate;
		std::getline(input, line);

		int year, month, day = 0;
		std::stringstream y, m, d;
		y << line.substr(0, 4);
		m << line.substr(5, 2);
		d << line.substr(8, 2);
		y >> year;
		m >> month;
		d >> day;

		if (line.length() < 14) {
			std::cerr << "Invalid Input Format : Input size too small\n";
			continue;
		}

		std::string raate = line.substr(13, line.find('\0'));

		float bitcoins = 0.00;
		std::stringstream bit;
		bit << raate;
		bit >> bitcoins;

		std::ostringstream dateStream;

		if (month < 10 && day < 10) {
			dateStream << year * 10 << month * 10 << day;
		} else if (day < 10) {
			dateStream << year << month * 10 << day;
		} else if (month < 10) {
			dateStream << year * 10 << month << day;
		} else {
			dateStream << year << month << day;
		}

		fulldate = dateStream.str();

		try { if (Parsing(year, month, day, raate, bitcoins, line) == 0)
			PrintOutput(fulldate, bitcoins);
		} catch (const BitcoinExchange::InvalidDateFormatException& e) {
			std::cerr << "Invalid Date Format Exception: " << e.what() << '\n';
		} catch (const BitcoinExchange::InvalidRateFormatException& e) {
			std::cerr << "Invalid Rate Format Exception: " << e.what() << '\n';
		} catch (const BitcoinExchange::InvalidPipeException& e) {
			std::cerr << "Invalid Pipe Exception: " << e.what() << '\n';
		}
	}
}
