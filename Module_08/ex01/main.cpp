/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 00:07:02 by alaaouam          #+#    #+#             */
/*   Updated: 2023/08/06 18:25:44 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

static void printVector(std::vector<int> vec)
{
	for (std::vector<int>::iterator iter = vec.begin(); iter != vec.end(); ++iter)
	{
        std::cout << *iter;
		if (iter + 1 != vec.end())
			std::cout << ", ";
	}
	std::cout << std::endl;
}

static void generalTest(void)
{
	Span numbers(10);
	Span empty(10);
	Span oneElement(10);
	
	size_t pos = 0;
	while (pos < 10)
	{
		numbers.addNumber(pos + 1);
		pos++;
	}
	
	std::cout << "GENERAL TEST" << std::endl;
	numbers.addNumber(pos + 1);
	printVector(numbers.getVector());
	std::cout << "The shortest span is: " << numbers.shortestSpan() << std::endl;
	std::cout << "The  longest span is: " << numbers.longestSpan() << std::endl;
	
	std::cout << std::endl;
	
	oneElement.addNumber(1);
	oneElement.shortestSpan();
	oneElement.longestSpan();
	empty.shortestSpan();
	empty.longestSpan();
}

static void addMoreNumbersTest(void)
{
	Span moreNumbers(10);

	std::cout << "ADD MORE NUMBERS TEST" << std::endl;
	moreNumbers.addMoreNumbers(5, 33);
	printVector(moreNumbers.getVector());
	moreNumbers.addMoreNumbers(15, 444);
	printVector(moreNumbers.getVector());
	moreNumbers.addNumber(3);
	std::cout << "The shortest span is: " << moreNumbers.shortestSpan() << std::endl;
	std::cout << "The  longest span is: " << moreNumbers.longestSpan() << std::endl;
}

static void subjectTest(void)
{
	Span sp = Span(5);
	
	std::cout << "SUBJECT EXAMPLE TEST" << std::endl;
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

/* static void crazyTest(void)
{
	Span lotsOfNumbers(10000);

	std::cout << "CRAZY TEST" << std::endl;
	lotsOfNumbers.addMoreNumbers(5000, 10000);
	printVector(lotsOfNumbers.getVector());
	lotsOfNumbers.addMoreNumbers(15000, 20000);
	printVector(lotsOfNumbers.getVector());
	lotsOfNumbers.addNumber(3);
	std::cout << "The shortest span is: " << lotsOfNumbers.shortestSpan() << std::endl;
	std::cout << "The  longest span is: " << lotsOfNumbers.longestSpan() << std::endl;
} */

int main(void)
{
	std::cout << std::endl;
	generalTest();
	std::cout << std::endl;
	addMoreNumbersTest();
	std::cout << std::endl;
	subjectTest();
	std::cout << std::endl;
	/* crazyTest();
	std::cout << std::endl; */
	
	return 0;
}