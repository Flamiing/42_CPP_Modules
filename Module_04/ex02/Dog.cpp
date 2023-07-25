/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 12:43:00 by alaaouam          #+#    #+#             */
/*   Updated: 2023/07/25 10:52:41 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << "✅ Dog default constructor called 🐶" << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain();
}

Dog::Dog(const Dog& other)
{
	std::cout << "✅ Dog default copy constructor called 🐶" << std::endl;
	this->_type = other._type;
	if (other._brain)
		this->_brain = new Brain(*other._brain);
}

Dog::~Dog(void)
{
	delete this->_brain;
	std::cout << "💥 Dog destructor called 🐶" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << "✅ Dog copy assignment operator called 🐶" << std::endl;
	if (this != &other)
	{
		_type = other._type;
		delete _brain;
		_brain = new Brain(*other._brain);
	}
	return *this;
}

void Dog::makeSound(void) const
{
	std::cout << "* bark * 🐶" << std::endl;
}

void Dog::changeIdea(int index, const std::string idea)
{
	this->_brain->setIdea(index, idea);
}

std::string Dog::thinkIdea(int index) const
{
	return this->_brain->getIdea(index);
}
