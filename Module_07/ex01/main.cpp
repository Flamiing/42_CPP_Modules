/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 14:40:57 by alaaouam          #+#    #+#             */
/*   Updated: 2023/08/04 15:20:18 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

void printString(std::string& str)
{
	std::cout << str << std::endl;
}

void isOddNumber(int& number)
{
	if (number % 2 != 0)
		std::cout << "Number: " << number << " is odd" << std::endl;
	else
		std::cout << "Number: " << number << " is not odd" << std::endl;
}

void multiplyByTen(int& number)
{
	number *= 10;
}

void printNumber(int& number)
{
	std::cout << "The Number is: " << number << std::endl;
}

int main(void)
{
	std::string array[] = 
	{
		"Never gonna give you up",
		"Never gonna let you down",
		"Never gonna run around and desert you",
		"Never gonna make you cry",
		"Never gonna say goodbye",
		"Never gonna tell a lie and hurt you"	
	};

	int numbers[] = {3, 4, 6, 8, 3923, 202, 21, 109, 2};
	
	std::cout << std::endl;
	::iter(array, 6, printString);
	std::cout << std::endl;
	::iter(numbers, 9, isOddNumber);
	std::cout << std::endl;
	::iter(numbers, 9, multiplyByTen);
	::iter(numbers, 9, printNumber);
	std::cout << std::endl;
	return 0;
}