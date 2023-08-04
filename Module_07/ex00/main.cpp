/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 13:46:50 by alaaouam          #+#    #+#             */
/*   Updated: 2023/08/04 14:48:36 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "whatever.hpp"

void subjectExampleTest(void)
{
	std::cout << "SUBJECT EXAMPLE TESTS" << std::endl;
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << ::min( a, b ) << std::endl;
	std::cout << "max(a, b) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min(c, d) = " << ::min( c, d ) << std::endl;
	std::cout << "max(c, d) = " << ::max( c, d ) << std::endl;
}

int main(void)
{
	std::string string1 = "this is sorter";
	std::string string2 = "this string is longer";
	int number1 = 123;
	int number2 = 12;
	double double1 = 3.14;
	double double2 = 18.8889;
	
	std::cout << std::endl;
	
	std::cout << "TESTS FOR MIN TEMPLATE" << std::endl;
	std::string min1 = ::min(string1, string2);
	std::string min2 = ::min(string1, string1);
	int min3 = ::min(number1, number2);
	int min4 = ::min(number1, number1);
	double min5 = ::min(double1, double2);
	double min6 = ::min(double1, double1);

	
	std::cout << "The min is: " << min1 << std::endl;
	std::cout << "The min is: " << min2 << std::endl;
	std::cout << "The min is: " << min3 << std::endl;
	std::cout << "The min is: " << min4 << std::endl;
	std::cout << "The min is: " << min5 << std::endl;
	std::cout << "The min is: " << min6 << std::endl;
	
	std::cout << std::endl;
	
	std::cout << "TESTS FOR MAX TEMPLATE" << std::endl;
	std::string max1 = ::max(string1, string2);
	std::string max2 = ::max(string1, string1);
	int max3 = ::max(number1, number2);
	int max4 = ::max(number1, number1);
	double max5 = ::max(double1, double2);
	double max6 = ::max(double1, double1);

	std::cout << "The max is: " << max1 << std::endl;
	std::cout << "The max is: " << max2 << std::endl;
	std::cout << "The max is: " << max3 << std::endl;
	std::cout << "The max is: " << max4 << std::endl;
	std::cout << "The max is: " << max5 << std::endl;
	std::cout << "The max is: " << max6 << std::endl;
	
	std::cout << std::endl;

	std::cout << "TESTS FOR SWAP TEMPLATE" << std::endl;
	std::cout << "String 1 before swap: " << string1 << std::endl;
	std::cout << "String 2 before swap: " << string2 << std::endl;
	::swap(string1, string2);
	std::cout << "String 1 after swap: " << string1 << std::endl;
	std::cout << "String 2 after swap: " << string2 << std::endl;
	std::cout << std::endl;
	std::cout << "Number 1 before swap: " << number1 << std::endl;
	std::cout << "Number 2 before swap: " << number2 << std::endl;
	::swap(number1, number2);
	std::cout << "Number 1 after swap: " << number1 << std::endl;
	std::cout << "Number 2 after swap: " << number2 << std::endl;
	std::cout << std::endl;
	std::cout << "Double 1 before swap: " << double1 << std::endl;
	std::cout << "Double 2 before swap: " << double2 << std::endl;
	::swap(double1, double2);
	std::cout << "Double 1 after swap: " << double1 << std::endl;
	std::cout << "Double 2 after swap: " << double2 << std::endl;
	
	
	std::cout << std::endl;

	subjectExampleTest();

	std::cout << std::endl;

	// This is a test to prove that the templates cannot be called with different types:
	/* ::swap(string1, number2);
	::min(string1, number2);
	::max(string1, number2); */
	
	return 0;
}
