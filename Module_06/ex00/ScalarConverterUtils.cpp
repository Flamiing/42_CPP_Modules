/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverterUtils.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 00:36:09 by alaaouam          #+#    #+#             */
/*   Updated: 2023/08/04 01:08:17 by alaaouam         ###   ########.fr       */
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

bool hasOverflow(const std::string& literal)
{
	std::string numberString;
	std::string lastDigitString;
	int lastDigitInt;
	int numberInt ;
	size_t lastDigitIndex;

	lastDigitIndex = literal.length();
	if ((literal[0] == '-' && lastDigitIndex > 11) || (literal[0] != '-' && lastDigitIndex > 10))
		return true;
	lastDigitIndex--;
	numberString = literal;
	numberString[lastDigitIndex] = 0;
	lastDigitInt = std::atoi(literal.c_str() + lastDigitIndex);
	numberInt = std::atoi(numberString.c_str());
	if (numberInt > 214748364 || (numberInt == 214748364 && lastDigitInt > 7))
		return true;
	else if (numberInt < -214748364 || (numberInt == -214748364 && lastDigitInt > 8))
		return true;
	else
		return false;
}