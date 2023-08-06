/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 00:07:20 by alaaouam          #+#    #+#             */
/*   Updated: 2023/08/06 17:40:12 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/* EXCEPTIONS */
const char* Span::MaxNumIntegersReached::what(void) const throw()
{
	return "Max number of integers reached!";
}

const char* Span::ImpossibleSpan::what(void) const throw()
{
	return "No span can be found!";
}

/* CONSTRUCTORS /// DESTRUCTOR /// OPERATOR */
Span::Span(void) {}

Span::Span(unsigned int n) : _max(n) {}

Span::Span(const Span& other) : _vec(other._vec), _max(other._max) {}

Span::~Span(void) {}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
	}
	return *this;
}

/* MEMBER FUNCTIONS */
const std::vector<int> Span::getVector(void) const
{
	return this->_vec;
}

void Span::addNumber(int newNum)
{
	try
	{
		if (this->_vec.size() == this->_max)
			throw Span::MaxNumIntegersReached();
		this->_vec.push_back(newNum);
	}
	catch (const std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int Span::longestSpan(void)
{
	try
	{
		if (this->_vec.size() < 2)
			throw Span::ImpossibleSpan();
		std::vector<int>::iterator iterMax = std::max_element(this->_vec.begin(), this->_vec.end());
		std::vector<int>::iterator iterMin = std::min_element(this->_vec.begin(), this->_vec.end());
		int max = *iterMax;
		int min = *iterMin;
		return max - min;
	}
	catch (const std::exception & e)
	{
		std::cerr << e.what() << std::endl;
		return -1;
	}
}

int Span::shortestSpan(void)
{
	try
	{
		if (this->_vec.size() < 2)
			throw Span::ImpossibleSpan();
		int result;
		int shortSpan = -1;
		for (std::vector<int>::iterator outerIter = this->_vec.begin(); outerIter != this->_vec.end(); ++outerIter) 
		{
			for (std::vector<int>::iterator innerIter = this->_vec.begin(); innerIter != this->_vec.end(); ++innerIter)
			{
				if (outerIter != innerIter)
				{
					if (*outerIter > *innerIter)
						result = *outerIter - *innerIter;
					else
						result = *innerIter - *outerIter;
					if (shortSpan == -1 || result < shortSpan)
						shortSpan = result;
				}
			}
    	}
		return shortSpan;
	}
	catch (const std::exception & e)
	{
		std::cerr << e.what() << std::endl;
		return -1;
	}
}

struct GenerateNumber 
{
    int& start;
    GenerateNumber(int& n) : start(n) {}

    int operator()()
	{
        return start++;
    }
};

void Span::addMoreNumbers(const unsigned int n, int start)
{
	try
	{
		unsigned int spaceLeft = this->_max - this->_vec.size();
		if (n > spaceLeft)
		{
			std::generate_n(std::back_inserter(this->_vec), spaceLeft, GenerateNumber(start));
			throw Span::MaxNumIntegersReached();
		}
		else
			std::generate_n(std::back_inserter(this->_vec), n, GenerateNumber(start));
	}
	catch (const std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
}
