/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 14:46:31 by alaaouam          #+#    #+#             */
/*   Updated: 2023/08/03 16:22:45 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.hpp"

static bool isChar(const std::string& literal)
{
	if (literal.length() > 1)
		return false;
	else if (std::isdigit(literal[0]))
		return false;
	else if (literal[0] >= 0 && literal[0] <= 127)
		return true;
	return false;
}

static bool isInt(const std::string& literal)
{
	int pos = 0;
	int	len = literal.length();
	
	if (len > 10)
		return false;
	while (pos < len)
	{
		std::cout << "TEST\n";
		if (!std::isdigit(literal[len]))
			return false;
		pos++;
	}
	return true;
}

static bool isFloat(const std::string& literal)
{
	int pos = 0;
	int	len = literal.length();
	int	dotCount = 0;
	
	if (len > 10)
		return false;
	while (pos < len)
	{
		if (!std::isdigit(literal[len]) && literal[pos] == 'f'
			&& pos != (len - 1) && literal[pos] != '.')
			return false;
		if (literal[pos] == '.')
			dotCount++;
		pos++;
	}
	if (literal[pos - 1] != 'f' || dotCount != 1)
		return false;
	return true;
}

static bool isDouble(const std::string& literal)
{
	int pos = 0;
	int	len = literal.length();
	int	dotCount = 0;
	
	if (len > 10)
		return false;
	while (pos < len)
	{
		if (!std::isdigit(literal[len]) && literal[pos] != '.')
			return false;
		if (literal[pos] == '.')
			dotCount++;
		pos++;
	}
	if (dotCount != 1)
		return false;
	return true;
}

static Types isSpecialType(const std::string& literal)
{
	if (literal == "+inff")
		return PLUSINFF;
	if (literal == "-inff")
		return MINUSINFF;
	if (literal == "nanf")
		return _NANF;
	if (literal == "+inf")
		return PLUSINF;
	if (literal == "-inf")
		return MINUSINF;
	if (literal == "nan")
		return _NAN;
	else
		return INVALID;
}

Types getType(const std::string& literal)
{
	if (literal.empty())
		return EMPTY;
	if (isChar(literal))
		return CHAR;
	if (isInt(literal))
		return INT;
	if (isFloat(literal))
		return FLOAT;
	if (isDouble(literal))
		return DOUBLE;
	return isSpecialType(literal);
}
