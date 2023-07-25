/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 12:43:15 by alaaouam          #+#    #+#             */
/*   Updated: 2023/07/25 10:52:28 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << "✅ Cat default constructor called 🐱" << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain();
}

Cat::Cat(const Cat& other)
{
	std::cout << "✅ Cat default copy constructor called 🐱" << std::endl;
	this->_type = other._type;
	if (other._brain)
		this->_brain = new Brain(*other._brain);
}

Cat::~Cat(void)
{
	delete this->_brain;
	std::cout << "💥 Cat destructor called 🐱" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "✅ Cat copy assignment operator called 🐱" << std::endl;
	if (this != &other)
	{
		_type = other._type;
		delete _brain;
		_brain = new Brain(*other._brain);
	}
	return *this;
}

void Cat::makeSound(void) const
{
	std::cout << "* meow * 🐱" << std::endl;
}

void Cat::changeIdea(int index, const std::string idea)
{
	this->_brain->setIdea(index, idea);
}

std::string Cat::thinkIdea(int index) const
{
	return this->_brain->getIdea(index);
}