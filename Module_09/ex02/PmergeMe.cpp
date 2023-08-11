/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 13:59:26 by alaaouam          #+#    #+#             */
/*   Updated: 2023/08/11 13:33:12 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/* CONSTRUCTORS /// DESTRUCTOR /// OPERATOR */
PmergeMe::PmergeMe(void) {}

PmergeMe::PmergeMe(const PmergeMe& other) { (void)other; }

PmergeMe::~PmergeMe(void) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) { (void)other; return *this; }

/* FUNCTIONS */
static bool onlyDigits(std::string& literal)
{
	size_t len = literal.length();
	size_t pos = 0;

	while (pos < len)
	{
		if (!std::isdigit(literal[pos]) && literal[pos] != '-')
			return false;
		if (literal[pos] == '-' && pos != 0)
			return false;
		pos++;
	}
	return true;
}

static bool hasOverflow(std::string& literal)
{
	std::string numberString;
	int lastDigitInt;
	int numberInt ;
	size_t lastDigitIndex;
	bool isNumber = onlyDigits(literal);
	bool isNegative = false;

	if (!isNumber)
		return false;
	numberString = literal;
	lastDigitIndex = literal.size();
	if (((literal[0] == '-' && lastDigitIndex > 11) || (literal[0] != '-' && lastDigitIndex > 10)))
		return true;
	lastDigitInt = std::atoi(literal.c_str() + lastDigitIndex - 1);
	numberInt = std::atoi(numberString.c_str());
	if (numberInt < 0)
	{
		numberInt *= -1;
		isNegative = true;
	}
	if (numberInt >= 214748364)
	{
		if (isNegative && numberInt == 214748364 && lastDigitInt > 8)
			return true;
		else if (!isNegative && numberInt == 214748364 && lastDigitInt > 7)
			return true;
		else if (numberInt > 214748364)
			return true;
	}
	return false;
}

static bool isDuplicate(const std::string& numbers, const std::string& number)
{
	std::istringstream iss(numbers);
	std::string token;
	size_t count = 0;

	while (iss >> token)
	{
		if (token == number)
			count++;
		if (count > 1)
			return true;
	}
	return false;
}

static bool invalidNumber(const std::string& numbersStr)
{
	std::istringstream iss(numbersStr);
	std::string token;

	while (iss >> token)
	{
		if (token[0] == '-' || hasOverflow(token)
			|| isDuplicate(numbersStr, token))
			return true;
	}
	return false;
}

static bool isNumber(char c)
{
	if (c >= '0' && c <= '9')
		return true;
	return false;
}

bool parseNumbers(const std::string& numbersStr)
{
	int spaceCount = 0;

	size_t pos = 0;
	while (pos < numbersStr.length())
	{
		if (numbersStr[pos] != ' ')
			spaceCount = 0;
		if (numbersStr[pos] == ' ')
			spaceCount++;
		if (spaceCount > 2)
			return false;
		if (!isNumber(numbersStr[pos]) && numbersStr[pos] != ' ')
			return false;
		pos++;
	}
	if (invalidNumber(numbersStr))
		return false;
	return true;
}

void numbersToContainers(const std::string& unsorted,
		std::vector<int>& vecNum, std::deque<int>& deqNum)
{
	int number;
	size_t findEnd;

	size_t pos = 0;
	while (pos < unsorted.length())
	{
		if (unsorted[pos] != ' ')
		{
			number = std::atoi(unsorted.c_str() + pos);
			vecNum.push_back(number);
			deqNum.push_back(number);
			findEnd = pos;
			while (unsorted[findEnd] && unsorted[findEnd] != ' ')
				findEnd++;
			pos = findEnd;
		}
		pos++;
	}
}

void sortVector(std::vector<int>& vecNum, double& elapsedTimeVector)
{
	clock_t start = clock();
	mergeInsertSort(vecNum, 0, vecNum.size() - 1, THRESHOLD);
	clock_t end = clock();
	elapsedTimeVector = (static_cast<double>(end - start) * 1000000.0 / CLOCKS_PER_SEC) / 1000.0;
}

void sortDeque(std::deque<int>& deqNum, double& elapsedTimeDeque)
{
	clock_t start = clock();
	mergeInsertSort(deqNum, 0, deqNum.size() - 1, THRESHOLD);
	clock_t end = clock();
	elapsedTimeDeque = (static_cast<double>(end - start) * 1000000.0 / CLOCKS_PER_SEC) / 1000.0;
}

void printElements(const std::vector<int>& container)
{
	std::vector<int>::const_iterator it = container.begin();
	std::vector<int>::const_iterator end = container.end();

	std::cout << "After:	";
	while (it != end)
	{
		if (it != container.begin())
			std::cout << " ";
		std::cout << *it;
		it++;
	}
	std::cout << std::endl;
}

void printResults(const std::string& unsorted, const std::vector<int>& vecNum,
		const std::deque<int>& deqNum, const double& elapsedTimeVector, const double& elapsedTimeDeque)
{
	std::cout << "Before:	" << unsorted << std::endl;
	printElements(vecNum);
	std::cout << "Time to process a range of " << vecNum.size()
						<<" elements with std::vector : " << elapsedTimeVector << "ms" << std::endl;
	std::cout << "Time to process a range of " << deqNum.size()
						<<" elements with std::Deque : " << elapsedTimeDeque << "ms" << std::endl;
}
