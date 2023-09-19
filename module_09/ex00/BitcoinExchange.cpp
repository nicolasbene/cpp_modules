/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:43:43 by nibenoit          #+#    #+#             */
/*   Updated: 2023/09/19 18:06:52 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

//constructors & destructors
Bitcoin::Bitcoin(void) {}
Bitcoin::Bitcoin(Bitcoin const &instance) {*this = instance;}
Bitcoin &Bitcoin::operator=(Bitcoin const &rhs) { (void)rhs, return (*this);}
Bitcoin::~Bitcoin(void) {}

Bitcoin::Bitcoin(std::string dataPath)
{
	std::ifstream file(dataPath);
	std::string line;
	std::vector<std::string> splitLine;
	std::string date;
	float value;

	if (file.is_open())
	{
		while (std::getline(file, line))
		{
			splitLine = splitString(line, ',');
			date = splitLine[0];
			value = std::stof(splitLine[1]);
			setData(date, value);
		}
		file.close();
	}
	else
		std::cout << "Unable to open file" << std::endl;
}


//getters & setters
void	Bitcoin::setData(std::string date, float value)
{
	data[date] = value;
}

std::map<std::string, float> Bitcoin::getData()
{
	return (data);
}

//member functions
void	Bitcoin::readInput(std::string inputPath)
{
	std::ifstream file(inputPath);
	std::string line;
	std::vector<std::string> splitLine;
	std::string date;
	float value;

	if (file.is_open())
	{
		while(std::getline(file, line))
		{
			splitLine = splitString(line, '|');
			date = splitLine[0];
			value = std::stof(splitLine[1]);
			if (data.find(date) != data.end())
				std::cout << date << " " << value << " " << data[date] << std::endl;
		}
		file.close();
	}
	else
		std::cout << "Unable to open file" << std::endl;
}

std::vector<std::string> Bitcoin::splitString(std::string str, char delimiter)
{
	std::vector<std::string> split;
	std::string tmp;
	std::stringstream ss(str);

	while (std::getline(ss, tmp, delimiter))
		split.push_back(tmp);
	return (split);
}
