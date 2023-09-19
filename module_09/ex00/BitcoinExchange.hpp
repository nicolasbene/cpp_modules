/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:35:11 by nibenoit          #+#    #+#             */
/*   Updated: 2023/09/19 17:47:38 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <vector>
#include <cctype>

class Bitcoin
{
private:
	std::map <std::string, float> data;
	// int readFlag;
public:
	Bitcoin();
	~Bitcoin();
	Bitcoin(std::string dataPath);
	Bitcoin& operator=(Bitcoin const &rhs);
	Bitcoin(Bitcoin const &instance);

	void setData(std::string date, float value);
	std::map<std::string, float> getData();

	void readInput(std::string inputPath);
	std::vector<std::string> splitString(std::string str, char delimiter);

};
#endif