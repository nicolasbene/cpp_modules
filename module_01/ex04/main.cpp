/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 14:42:05 by nibenoit          #+#    #+#             */
/*   Updated: 2023/08/09 15:39:11 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <fstream>

static int	usage(std::string prog_name)
{
	std::cout << "Usage: " << prog_name << " <filename> <to_find> <replace_by>\n";
	return 1;
}

static void	replace(std::string &line, size_t pos, int len, std::string word)
{
	line = line.substr(0, pos) + word + line.substr(pos + len);
}

int	main(int ac, char **av)
{
	size_t			len;
	size_t			pos;
	std::string		line;
	std::string		to_find;
	std::string		replace_by;
	std::string		filename;
	std::ifstream	in;
	std::ofstream	out;

	if (ac != 4)
		return usage(av[0]);

	filename = av[1];
	if (std::string().compare(av[2]) == 0) {
		std::cout << "Can't replace nothing" << std::endl;
		return 2;
	}
	in.open(filename.c_str(), std::ifstream::in);
	if (!in) {
		std::cout << "Unable to open the input file\n";
		return 3;
	}

	out.open((filename + ".replace").c_str(), std::ofstream::out);
	if (!out) {
		in.close();
		std::cout << "Unable to open the output file\n";
		return 4;
	}

	to_find = av[2];
	replace_by = av[3];
	len = to_find.length();
	while (getline(in, line)) {
		pos = line.find(to_find);
		while (pos != std::string::npos) {
			replace(line, pos, len, replace_by);
			pos = line.find(to_find, pos + replace_by.length());
		}
		out << line << "\n";
	}
	in.close();
	out.close();
	return 0;
}
