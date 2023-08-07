/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 18:40:53 by alaaouam          #+#    #+#             */
/*   Updated: 2023/08/07 13:06:46 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iterator>
#include <list>
#include "MutantStack.hpp"

void subjectExampleTest(void)
{
	std::cout << "TEST: SUBJECT EXAMPLE" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
}

void compareWithListTest(void)
{
	std::cout << "TEST: COMPARE WITH LIST" << std::endl;

	MutantStack<int> myMutantStack;
	myMutantStack.push(5);
	myMutantStack.push(17);
	myMutantStack.push(3);
	myMutantStack.push(5);
	myMutantStack.push(737);
	myMutantStack.push(0);
	MutantStack<int>::iterator mutantStackIter = myMutantStack.begin();

	std::list<int> myList;
	myList.push_back(5);
	myList.push_back(17);
	myList.push_back(3);
	myList.push_back(5);
	myList.push_back(737);
	myList.push_back(0);
	std::list<int>::iterator listIter = myList.begin();
	std::list<int>::iterator end = myList.end();
	
	int testFailed = 0;
	while (listIter != end)
	{
		if (*listIter != *mutantStackIter)
		{
			testFailed = 1;
			std::cout << "\033[31mTEST FAILED!\033[0m" << std::endl;
			break ;
		}
		mutantStackIter++;
		listIter++;
	}
	if (!testFailed)
		std::cout << "\033[32mTEST PASSED!\033[0m" << std::endl;
}

void testCopyAndCopyConstructor(void)
{
	std::cout << "TEST: COPY AND COPY CONSTRUCTOR" << std::endl;
	MutantStack<std::string> stringStack;

	const std::string strings[] = 
	{
		"Never gonna give you up",
		"Never gonna let you down",
		"Never gonna run around and desert you",
		"Never gonna make you cry",
		"Never gonna say goodbye",
		"Never gonna tell a lie and hurt you"	
	};

	size_t pos = 0;
	while (pos < 6)
	{
		stringStack.push(strings[pos]);
		pos++;
	}
	
	MutantStack<std::string> test1(stringStack);
	MutantStack<std::string> test2;
	test2 = stringStack;

	MutantStack<std::string>::iterator stringStackIter = stringStack.begin();
	MutantStack<std::string>::iterator stringStackEnd = stringStack.begin();
	MutantStack<std::string>::iterator iterTest1 = test1.begin();
	MutantStack<std::string>::iterator iterTest2 = test2.begin();

	int testFailed = 0;
	while (stringStackIter != stringStackEnd)
	{
		if (*stringStackIter != *iterTest1 || *stringStackIter != *iterTest2)
		{
			testFailed = 1;
			std::cout << "\033[31mTEST FAILED!\033[0m" << std::endl;
			break ;
		}
		stringStackIter++;
		iterTest1++;
		iterTest2++;
	}
	if (!testFailed)
		std::cout << "\033[32mTEST PASSED!\033[0m" << std::endl;
}

int main(void)
{
	std::cout << std::endl;
	subjectExampleTest();
	std::cout << std::endl;
	compareWithListTest();
	std::cout << std::endl;
	testCopyAndCopyConstructor();
	std::cout << std::endl;
	
	return 0;
}