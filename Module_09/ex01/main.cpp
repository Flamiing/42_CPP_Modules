/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 13:56:28 by alaaouam          #+#    #+#             */
/*   Updated: 2023/08/09 00:47:36 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int howToUse(void)
{
	std::cout << "Error: wrong number of arguments." << std::endl;
	std::cout << "./RPN \"<expression>\"" << std::endl;
	return 1;
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return howToUse();
	
	float result;
	if (RPN::reversePolishNotation(argv[1], result))
	{
		std::cout << result << std::endl;
		return 0;
	}
	else
		return 1;
}