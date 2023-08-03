/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 12:30:20 by alaaouam          #+#    #+#             */
/*   Updated: 2023/08/04 01:10:19 by alaaouam         ###   ########.fr       */
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

/* MEMBER FUNCTION */
void ScalarConverter::convert(const std::string& literal)
{
	char charConverted;
	int intConverted;
	float floatConverted;
	double doubleConverted;
	std::string specialValue;
	Types literalType = getType(literal);

	if (literalType == EMPTY || literalType == INVALID
		|| (literalType == INT && hasOverflow(literal)))
	{
		if (literalType == EMPTY)
			std::cerr << "Error: Literal is empty and cannot be converted" << std::endl;
		else if (literalType == INT)
			std::cerr << "Error: Int overflow detected" << std::endl;
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
