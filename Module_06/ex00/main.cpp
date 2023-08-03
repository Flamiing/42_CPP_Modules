/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 12:19:58 by alaaouam          #+#    #+#             */
/*   Updated: 2023/08/03 16:03:18 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScalarConverter.hpp"

void howToUse(void)
{
	std::cerr << "Error: Wrong number of parameters" << std::endl;
	std::cerr << "Usage: ./convert <literal_to_convert>" << std::endl;
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		howToUse();
		return 1;
	}
	ScalarConverter::convert(argv[1]);
	return 0;
}