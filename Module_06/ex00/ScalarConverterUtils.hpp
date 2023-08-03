/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverterUtils.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 00:32:03 by alaaouam          #+#    #+#             */
/*   Updated: 2023/08/04 01:06:25 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTERUTILS_HPP
# define SCALARCONVERTERUTILS_HPP

# include <iostream>
# include <string>
# include <cctype>
# include "ScalarConverterTypes.hpp"

bool hasOverflow(const std::string& literal);
void printSpecialValue(const std::string& specialValue);
void printConversions(char& charConverted, int& intConverted,
		float& floatConverted, double& doubleConverted);
void getMainType(Types type, const std::string& literal, std::string& specialValue,
char& charConverted, int& intConverted, float& floatConverted, double& doubleConverted);
void conversion(Types type, char& charConverted, int& intConverted,
		float& floatConverted, double& doubleConverted);

#endif