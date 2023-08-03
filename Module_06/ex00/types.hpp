/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 14:45:59 by alaaouam          #+#    #+#             */
/*   Updated: 2023/08/03 16:19:33 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_HPP
# define TYPES_HPP

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