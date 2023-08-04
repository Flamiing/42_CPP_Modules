/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverterUtils.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 00:36:09 by alaaouam          #+#    #+#             */
/*   Updated: 2023/08/04 02:36:40 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverterUtils.hpp"

static void setSpecialValue(Types type, std::string& specialValue)
{
	if (type == PLUSINFF)
		specialValue = "+inff";
	else if (type == MINUSINFF)
		specialValue = "-inff";
	else if (type == _NANF)
		specialValue = "nanf";
	else if (type == PLUSINF)
		specialValue = "+inf";
	else if (type == MINUSINF)
		specialValue = "-inf";
	else if (type == _NAN)
		specialValue = "nan";
}

void getMainType(Types type, const std::string& literal, std::string& specialValue,
char& charConverted, int& intConverted, float& floatConverted, double& doubleConverted)
{
	if (type == CHAR)
		charConverted = literal[0];
	else if (type == INT)
		intConverted = std::atoi(literal.c_str());
	else if (type == FLOAT)
		floatConverted = std::atof(literal.c_str());
	else if (type == DOUBLE)
		doubleConverted = std::stod(literal.c_str());
	else
		setSpecialValue(type, specialValue);
}

void conversion(Types type, char& charConverted, int& intConverted,
		float& floatConverted, double& doubleConverted)
{
	if (type == CHAR)
	{
		intConverted = static_cast<int>(charConverted);
		floatConverted = static_cast<float>(charConverted);
		doubleConverted = static_cast<double>(charConverted);
	}
	else if (type == INT)
	{
		charConverted = static_cast<char>(intConverted);
		floatConverted = static_cast<float>(intConverted);
		doubleConverted = static_cast<double>(intConverted);
	}
	else if (type == FLOAT)
	{
		charConverted = static_cast<char>(floatConverted);
		intConverted = static_cast<int>(floatConverted);
		doubleConverted = static_cast<double>(floatConverted);
	}
	else if (type == DOUBLE)
	{
		charConverted = static_cast<char>(doubleConverted);
		intConverted = static_cast<int>(doubleConverted);
		floatConverted = static_cast<float>(doubleConverted);
	}
}

static size_t getLastDigitBeforePoint(std::string& numberString)
{
	size_t pos = 0;
	size_t len = numberString.length();
	
	while (pos < len)
	{
		if (numberString[pos] == '.')
			break ;
		pos++;
	}
	numberString[pos - 1] = 0;
	return pos;
}

bool hasOverflow(const std::string& literal)
{
	std::string numberString;
	int lastDigitInt;
	int numberInt ;
	size_t lastDigitIndex;
	bool isNumber = onlyDigits(literal);
	bool isNegative = false;

	if (!isNumber)
		return false;
	numberString = literal;
	lastDigitIndex = getLastDigitBeforePoint(numberString);
	if (((literal[0] == '-' && lastDigitIndex > 11) || (literal[0] != '-' && lastDigitIndex > 10)))
		return true;
	lastDigitInt = std::atoi(literal.c_str() + lastDigitIndex - 1);
	numberInt = std::atoi(numberString.c_str());
	if (numberInt < 0)
	{
		numberInt *= -1;
		isNegative = true;
	}
	if (numberInt >= 214748364)
	{
		if (isNegative && numberInt == 214748364 && lastDigitInt > 8)
			return true;
		else if (!isNegative && numberInt == 214748364 && lastDigitInt > 7)
			return true;
		else if (numberInt > 214748364)
			return true;
	}
	return false;
}
