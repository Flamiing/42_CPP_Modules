/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverterTypes.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 14:45:59 by alaaouam          #+#    #+#             */
/*   Updated: 2023/08/04 00:46:02 by alaaouam         ###   ########.fr       */
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

Types getType(const std::string& literal);

#endif