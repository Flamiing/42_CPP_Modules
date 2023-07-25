/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 15:20:31 by alaaouam          #+#    #+#             */
/*   Updated: 2023/07/25 10:45:26 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "✅ Brain default constructor called 🧠" << std::endl;
}

Brain::Brain(const Brain& other)
{
	std::cout << "✅ Brain copy constructor called 🧠" << std::endl;
	size_t pos = 0;
	while (pos < 100)
	{
			_ideas[pos] = other._ideas[pos];
			pos++;
	}
}

Brain::~Brain(void)
{
	std::cout << "💥 Brain destructor called 🧠" << std::endl;
}

Brain& Brain::operator=(const Brain& other)
{
	std::cout << "✅ Brain copy assignment operator called 🧠" << std::endl;
	size_t pos = 0;
	if (this != &other)
	{
		while (pos < 100)
		{
			_ideas[pos] = other._ideas[pos];
			pos++;
		}
	}
	return *this;
}

void Brain::setIdea(int index, const std::string idea)
{
	if (index > 99)
		std::cout << "Animals don't think that much!" << std::endl;
	else
	{
		if (idea.empty())
			this->_ideas[index] = "NOTHING";
		else
			this->_ideas[index] = idea;
		
	}
}

std::string Brain::getIdea(int index) const
{
	if (index > 99)
	{
		std::cout << "Animals don't think that much!" << std::endl;
		return "NOTHING";
	}
	else
	{
		if (this->_ideas[index].empty())
			return "NOTHING";
		return this->_ideas[index];
	}
}
