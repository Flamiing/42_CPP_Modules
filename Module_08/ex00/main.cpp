/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 23:02:41 by alaaouam          #+#    #+#             */
/*   Updated: 2023/08/05 23:51:40 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <deque>
#include <set>
#include <vector>
#include <list>
#include "easyfind.hpp"

void printResult(int result)
{
	if (result != -1)
		std::cout << "Int was found!" << std::endl;
	else
		std::cout << "Int was not found!" << std::endl;
}

template<typename T>
void testContainer(T& container, size_t count)
{
	std::cout << std::endl;
	std::cout << "TEST " << count << ":" << std::endl;
	printResult(easyfind(container, 3));
	printResult(easyfind(container, 666));
	std::cout << std::endl;
	count++;
}

int main(void)
{
	size_t pos = 0;
	
	std::vector<int> vec;
	std::deque<int> deq;
	std::list<int> lst;
	std::set<int> st;
	
	while (pos < 20)
	{
		vec.push_back(pos + 1);
		deq.push_back(pos + 1);
		lst.push_back(pos + 1);
		st.insert(pos + 1);
		pos++;
	}
	
	testContainer(vec, 1);
	testContainer(deq, 2);
	testContainer(lst, 3);
	testContainer(st, 4);
	
	return 0;
}