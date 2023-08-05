/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 15:22:40 by alaaouam          #+#    #+#             */
/*   Updated: 2023/08/05 18:35:11 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include "Array.hpp"

#define MAX_VAL 33
#define ABC_LEN 26
#define ABC 65

template<typename T>
void printElements(Array<T> array)
{
	unsigned int pos = 0;
	
	while (pos < array.size())
	{
		std::cout << array[pos] << std::endl;
		pos++;
	}
}

template<typename T>
void printArray(T* array, unsigned int size)
{
	unsigned int pos = 0;
	
	while (pos < size)
	{
		std::cout << array[pos] << std::endl;
		pos++;
	}
}

void emptyArrayTest(void)
{
	std::cout << "EMPTY ARRAY TEST" << std::endl;
	Array<int> intEmptyArray;
	Array<char> charEmptyArray;
	Array<std::string> stringEmptyArray;

	try
	{
		std::cout << "Array size: " << intEmptyArray.size() << std::endl;
		int testInt = intEmptyArray[0];
		(void)testInt;
	}
	catch (const std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	try
	{
		std::cout << "Array size: " << charEmptyArray.size() << std::endl;
		char testChar = charEmptyArray[0];
		(void)testChar;
	}
	catch (const std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	try
	{
		std::cout << "Array size: " << stringEmptyArray.size() << std::endl;
		std::string testString = stringEmptyArray[0];
		(void)testString;
	}
	catch (const std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void intTest(void)
{
	std::cout << "TEST WITH INTEGERS" << std::endl;
	Array<int> array(MAX_VAL);
	int *mirrorArray = new int[MAX_VAL];

	size_t pos = 0;
	while (pos < MAX_VAL)
	{
		array[pos] = pos;
		mirrorArray[pos] = pos;
		pos++;
	}
	
	std::cout << "Array:" << std::endl;
	printElements(array);
	std::cout << "Mirror Array:" << std::endl;
	printArray(mirrorArray, MAX_VAL);
	try
	{
		std::cout << array[9348] << std::endl;
	}
	catch (const std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << array[-1] << std::endl;
	}
	catch (const std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << "Array size: " << array.size() << std::endl;

	delete[] mirrorArray;
}

void charTest(void)
{
	std::cout << "TEST WITH CHARACTERS" << std::endl;
	Array<char> array(ABC_LEN);
	char *mirrorArray = new char[ABC_LEN];

	size_t pos = 0;
	while (pos < ABC_LEN)
	{
		array[pos] = pos + ABC;
		mirrorArray[pos] = pos + ABC;
		pos++;
	}
	
	std::cout << "Array:" << std::endl;
	printElements(array);
	std::cout << "Mirror Array:" << std::endl;
	printArray(mirrorArray, ABC_LEN);
	try
	{
		std::cout << array[9348] << std::endl;
	}
	catch (const std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << array[-1] << std::endl;
	}
	catch (const std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << "Array size: " << array.size() << std::endl;

	delete[] mirrorArray;
}

void complexTypeTest(void)
{
	std::cout << "TEST WITH STRINGS" << std::endl;
	Array<std::string> array(6);
	std::string *mirrorArray = new std::string[6];

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
		array[pos] = strings[pos];
		mirrorArray[pos] = strings[pos];
		pos++;
	}
	
	std::cout << "Array:" << std::endl;
	printElements(array);
	std::cout << "Mirror Array:" << std::endl;
	printArray(mirrorArray, 6);
	try
	{
		std::cout << array[9348] << std::endl;
	}
	catch (const std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << array[-1] << std::endl;
	}
	catch (const std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << "Array size: " << array.size() << std::endl;
	
	delete[] mirrorArray;
}

void deepCopyTest(void)
{
	std::cout << "DEEP COPY TEST" << std::endl;
	Array<int> mainArray(3);
	
	size_t pos = 0;
	while (pos < 3)
	{
		mainArray[pos] = pos + 1;
		pos++;
	}
	
	Array<int> testArray1(mainArray);
	Array<int> testArray2 = mainArray;

	pos = 0;
	while (pos < 3)
	{
		testArray1[pos] *= 2;
		pos++;
	}

	pos = 0;
	while (pos < 3)
	{
		testArray2[pos] *= 3;
		pos++;
	}

	std::cout << "Main array values: " << std::endl;
	printElements(mainArray);
	std::cout << "Test1 array values: " << std::endl;
	printElements(testArray1);
	std::cout << "Test2 array values: " << std::endl;
	printElements(testArray2);
	
}

int main(void)
{
	std::cout << std::endl;
	emptyArrayTest();
	std::cout << std::endl;
	intTest();
	std::cout << std::endl;
	charTest();
	std::cout << std::endl;
	complexTypeTest();
	std::cout << std::endl;
	deepCopyTest();
	std::cout << std::endl;
	
	return 0;
}