/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverterPrint.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 00:31:01 by alaaouam          #+#    #+#             */
/*   Updated: 2023/08/04 00:44:31 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverterUtils.hpp"

static bool hasDecimals(double& number)
{
	double integralPart = 0.0;
	double fractionalPart = std::modf(number, &integralPart);
	return fractionalPart != 0.0;
}

void printConversions(char& charConverted, int& intConverted,
		float& floatConverted, double& doubleConverted)
{
	if (!std::isprint(static_cast<unsigned char>(charConverted))
		|| intConverted > 127 || intConverted < 0)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << charConverted << "'" << std::endl;
	std::cout << "int: " << intConverted << std::endl;
	if (!hasDecimals(doubleConverted))
	{
		std::cout << "float: " << floatConverted << ".0f" << std::endl;
		std::cout << "double: " << doubleConverted << ".0" << std::endl;
	}
	else
	{
		std::cout << "float: " << floatConverted << "f" << std::endl;
		std::cout << "double: " << doubleConverted << std::endl;
	}
}

void printSpecialValue(const std::string& specialValue)
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