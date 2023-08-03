/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 12:30:20 by alaaouam          #+#    #+#             */
/*   Updated: 2023/08/03 16:15:09 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/* CONSTRUCTORS /// DESTRUCTOR /// OPERATOR */
ScalarConverter::ScalarConverter(void)
{

}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void)other;
}

ScalarConverter::~ScalarConverter(void)
{

}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return *this;
}

/* SUPLEMENTARY FUNCTIONS */
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

static void getMainType(Types type, const std::string& literal, std::string& specialValue,
char& charConverted, int& intConverted, float& floatConverted, double& doubleConverted)
{
	if (type == CHAR)
		charConverted = literal[0];
	else if (type == INT)
		intConverted = std::atoi(literal.c_str());
	else if (type == FLOAT)
		floatConverted = std::atof(literal.c_str());
	else if (type == DOUBLE)
		doubleConverted = std::atof(literal.c_str());
	else
		setSpecialValue(type, specialValue);
}

static void conversion(Types type, char& charConverted, int& intConverted,
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

static void printConversions(char& charConverted, int& intConverted,
		float& floatConverted, double& doubleConverted)
{
	if (!std::isprint(static_cast<unsigned char>(charConverted)))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "char: " << charConverted << std::endl;
	std::cout << "int: " << intConverted << std::endl;
	std::cout << "float: " << floatConverted << std::endl;
	std::cout << "double: " << doubleConverted << std::endl;
}

static void printSpecialValue(const std::string& specialValue)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (specialValue == "-inff")
	{
		std::cout << "float: " << specialValue << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
	else if (specialValue == "+inff")
	{
		std::cout << "float: " << specialValue << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (specialValue == "nanf")
	{
		std::cout << "float: " << specialValue << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (specialValue == "-inf")
	{
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: " << specialValue << std::endl;
	}
	else if (specialValue == "+inf")
	{
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: " << specialValue << std::endl;
	}
	else if (specialValue == "nan")
	{
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: " << specialValue << std::endl;
	}
}

/* MEMBER FUNCTION */
void ScalarConverter::convert(const std::string& literal)
{
	char charConverted;
	int intConverted;
	float floatConverted;
	double doubleConverted;
	std::string specialValue;
	Types literalType = getType(literal);

	if (literalType == EMPTY || literalType == INVALID)
	{
		if (literalType == EMPTY)
			std::cerr << "Error: Literal is empty and cannot be converted" << std::endl;
		else
			std::cerr << "Error: Literal is invalid and cannot be converted" << std::endl;
		return ;
	}
	getMainType(literalType, literal, specialValue, charConverted,
			intConverted, floatConverted, doubleConverted);
	conversion(literalType, charConverted, intConverted,
			floatConverted, doubleConverted);
	if (specialValue.empty())
		printConversions(charConverted, intConverted,
				floatConverted, doubleConverted);
	else
		printSpecialValue(specialValue);
}
