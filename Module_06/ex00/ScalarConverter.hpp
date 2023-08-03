/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 12:34:20 by alaaouam          #+#    #+#             */
/*   Updated: 2023/08/04 00:46:18 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include "ScalarConverterTypes.hpp"
# include "ScalarConverterUtils.hpp"

class ScalarConverter
{
	public:
		static void convert(const std::string& literal);
	private:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter& other);
		~ScalarConverter(void);
		
		ScalarConverter& operator=(const ScalarConverter& other);
};

#endif