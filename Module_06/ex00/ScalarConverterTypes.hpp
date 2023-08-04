/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverterTypes.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 14:45:59 by alaaouam          #+#    #+#             */
/*   Updated: 2023/08/04 02:11:09 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTERTYPES_HPP
# define SCALARCONVERTERTYPES_HPP

# include <iostream>
# include <string>
# include <cctype>

enum Types
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PLUSINFF,
	MINUSINFF,
	_NANF,
	PLUSINF,
	MINUSINF,
	_NAN,
	INVALID,
	EMPTY
};

bool onlyDigits(const std::string& literal);
Types getType(const std::string& literal);

#endif