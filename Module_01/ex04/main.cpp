/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 16:21:42 by alaaouam          #+#    #+#             */
/*   Updated: 2023/07/23 23:59:52 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>

static int	openFiles(const std::string &filename, std::ifstream &input, std::ofstream &output)
{
	input.open(filename, std::ios::in);
	if (!input.is_open())
	{
		std::cerr << "Error: Can't open file or is not accessible" << std::endl;
		return (-1);
	}
	else if (input.peek() == std::ifstream::traits_type::eof())
	{
		input.close();
		std::cerr << "Error: File is empty" << std::endl;
		return (-1);
	}
	output.open(filename + ".replace", std::ios::out);
	if (!output.is_open())
	{
		input.close();
		std::cerr << "Error: Can't open file or is not accessible" << std::endl;
		return (-1);
	}
	return (0);
}

static void	findAndReplace(std::string &text, const std::string &find, const std::string &replace)
{
	size_t	pos = 0;

	while ((pos = text.find(find, pos)) != std::string::npos)
	{
		text.erase(pos, find.length());
		text.insert(pos, replace);
		pos += replace.length();
	}
}

static int	readReplaceAndSave(const std::string &filename, const std::string &find, const std::string &replace)
{
	std::ifstream	input;
	std::ofstream	output;
	std::ostringstream	oss;
	std::string	buffer;

	if (openFiles(filename, input, output) == -1)
		return (1);
	oss << input.rdbuf();
	buffer = oss.str();
	findAndReplace(buffer, find, replace);
	output << buffer;
	input.close();
	output.close();
	return (0);
}

static void	howToUse(void)
{
	std::cerr << "Error: Wrong number of arguments!" << std::endl;
	std::cerr << "Usage: ./replace <filename> <find> <replace>" << std::endl;
}

int	main(int argc, char **argv)
{
	std::string	filename;
	std::string	find;
	std::string	replace;
	
	if (argc != 4)
	{
		howToUse();
		return (1);
	}
	filename = std::string(argv[1]);
	find = std::string(argv[2]);
	replace = std::string(argv[3]);
	if (readReplaceAndSave(filename, find, replace) != 0)
		return (1);
	return (0);
}