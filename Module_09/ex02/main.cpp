/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 13:56:28 by alaaouam          #+#    #+#             */
/*   Updated: 2023/08/11 13:15:47 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <deque>
#include "PmergeMe.hpp"

int howToUse(void)
{
	std::cout << "Error: no arguments passed" << std::endl;
	std::cout << "Usage: ./PmergeMe <num1> <num2> <num3> <num4> ..." << std::endl;
	return 1;
}

std::string concatenateIntoString(char** array)
{
	std::string newStr = "";
	size_t pos = 0;

	while (array[pos])
	{
		if (!newStr.empty())
			newStr += " ";
		newStr += array[pos];
		pos++;
	}
	return newStr;
} 

int main(int argc, char **argv)
{
	if (argc == 1)
		return howToUse();
	
	std::deque<int> myDeque;
	std::string numberList = concatenateIntoString(argv + 1);
	
	if (!PmergeMe::sortNumbers(numberList, myDeque))
	{
		std::cout << "Error" << std::endl;
		return 1;
	}
	return 0;
}