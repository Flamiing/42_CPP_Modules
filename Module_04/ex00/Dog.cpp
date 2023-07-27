/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 12:43:00 by alaaouam          #+#    #+#             */
/*   Updated: 2023/07/27 17:37:56 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << "✅ Dog default constructor called 🐶" << std::endl;
	this->_type = "Dog";
}

Dog::Dog(const Dog& other)
{
	std::cout << "✅ Dog default copy constructor called 🐶" << std::endl;
	this->_type = other._type;
}

Dog::~Dog(void)
{
	std::cout << "💥 Dog destructor called 🐶" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << "Dog copy assignment operator called 🐶" << std::endl;
	if (this != &other)
		_type = other._type;
	return *this;
}

void Dog::makeSound(void) const
{
	std::cout << "* woof * 🐶" << std::endl;
}
