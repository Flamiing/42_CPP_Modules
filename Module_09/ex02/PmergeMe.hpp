/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 13:59:24 by alaaouam          #+#    #+#             */
/*   Updated: 2023/08/10 21:32:20 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGERME_HPP
# define PMERGERME_HPP

# include <iostream>
# include <sstream>
# include <typeinfo>
# include <vector>
# include <deque>

# define THRESHOLD 10

void sortVector(std::vector<int>& vecNum, double& elapsedTimeVector);
void sortDeque(std::deque<int>& deqNum, double& elapsedTimeDeque);
bool parseNumbers(const std::string& numbersStr);
void numbersToContainers(const std::string& unsorted,
		std::vector<int>& vecNum, std::deque<int>& deqNum);
void printResults(const std::string& unsorted, const std::vector<int>& vecNum,
		const std::deque<int>& deqNum, const double& elapsedTimeVector, const double& elapsedTimeDeque);

template<typename Container>
void getSortedContainer(Container& sorted, std::vector<int>& vecNum, std::deque<int>& deqNum)
{
	const std::type_info& type = typeid(sorted);
	if (type == typeid(vecNum))
		std::copy(vecNum.begin(), vecNum.end(), sorted.begin());
	else if (type == typeid(deqNum))
		std::copy(deqNum.begin(), deqNum.end(), sorted.begin());
}

template<typename Container>
static void merge(Container& numbers, int left, int mid, int right)
{
    int num1 = mid - left + 1;
    int num2 = right - mid;

    Container leftContainer(num1);
    Container rightContainer(num2);

    for (int leftPos = 0; leftPos < num1; leftPos++)
        leftContainer[leftPos] = numbers[left + leftPos];
    for (int rightPos = 0; rightPos < num2; rightPos++)
        rightContainer[rightPos] = numbers[mid + 1 + rightPos];

    int leftPos = 0;
    int rightPos = 0;
    int pos = left;

    while (leftPos < num1 && rightPos < num2) {
        if (leftContainer[leftPos] <= rightContainer[rightPos]) {
            numbers[pos] = leftContainer[leftPos];
            leftPos++;
        } else {
            numbers[pos] = rightContainer[rightPos];
            rightPos++;
        }
        pos++;
    }

    while (leftPos < num1) {
        numbers[pos] = leftContainer[leftPos];
        leftPos++;
        pos++;
    }

    while (rightPos < num2) {
        numbers[pos] = rightContainer[rightPos];
        rightPos++;
        pos++;
    }
}

template<typename Container>
static void insertionSort(Container& numbers, int left, int right)
{
    for (int pos = left + 1; pos <= right; ++pos) {
        int key = numbers[pos];
        int index = pos - 1;
        while (index >= left && numbers[index] > key) {
            numbers[index + 1] = numbers[index];
            --index;
        }
        numbers[index + 1] = key;
    }
}

template<typename Container>
void mergeInsertSort(Container& numbers, int left, int right, int insertionThreshold)
{
    if (left < right)
	{
        if (right - left <= insertionThreshold)
            insertionSort(numbers, left, right);
		else
		{
            int mid = left + (right - left) / 2;
            mergeInsertSort(numbers, left, mid, insertionThreshold);
            mergeInsertSort(numbers, mid + 1, right, insertionThreshold);
            merge(numbers, left, mid, right);
        }
    }
}

class PmergeMe
{
	public:
		template<typename Container>
		static bool sortNumbers(const std::string& numbersStr, Container& sorted)
		{	
			std::string unsorted;
			std::vector<int> vecNum;
			std::deque<int> deqNum;
			double elapsedTimeVector;
			double elapsedTimeDeque;
			
			if (!parseNumbers(numbersStr))
				return false;
			unsorted = numbersStr;

			numbersToContainers(unsorted, vecNum, deqNum);

			sortVector(vecNum, elapsedTimeVector);
			sortDeque(deqNum, elapsedTimeDeque);

			printResults(unsorted, vecNum, deqNum, elapsedTimeVector, elapsedTimeDeque);
			
			getSortedContainer(sorted, vecNum, deqNum);
			return true;
		}
	private:
		PmergeMe(void);
		PmergeMe(const PmergeMe& other);
		~PmergeMe(void);
		
		PmergeMe& operator=(const PmergeMe& other);
};

#endif