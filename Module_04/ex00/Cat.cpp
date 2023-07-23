/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 12:43:15 by alaaouam          #+#    #+#             */
/*   Updated: 2023/07/23 14:04:07 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	this->_type = "Cat";
	std::cout << "✅ Cat default constructor called 🐱" << std::endl;
}

Cat::Cat(const Cat& other)
{
	this->_type = other._type;
	std::cout << "✅ Cat default copy constructor called 🐱" << std::endl;
}

Cat::~Cat(void)
{
	std::cout << "💥 Cat destructor called 🐱" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
		_type = other._type;
	std::cout << "Cat copy assignment operator called 🐱" << std::endl;
	return *this;
}

void Cat::makeSound(void) const
{
	std::cout << "* meow * 🐱" << std::endl;
}