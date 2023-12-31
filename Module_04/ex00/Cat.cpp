/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 12:43:15 by alaaouam          #+#    #+#             */
/*   Updated: 2023/07/23 15:37:25 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << "✅ Cat default constructor called 🐱" << std::endl;
	this->_type = "Cat";
}

Cat::Cat(const Cat& other)
{
	std::cout << "✅ Cat default copy constructor called 🐱" << std::endl;
	this->_type = other._type;
}

Cat::~Cat(void)
{
	std::cout << "💥 Cat destructor called 🐱" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Cat copy assignment operator called 🐱" << std::endl;
	if (this != &other)
		_type = other._type;
	return *this;
}

void Cat::makeSound(void) const
{
	std::cout << "* meow * 🐱" << std::endl;
}