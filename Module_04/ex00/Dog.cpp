/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 12:43:00 by alaaouam          #+#    #+#             */
/*   Updated: 2023/07/23 14:04:11 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	this->_type = "Dog";
	std::cout << "✅ Dog default constructor called 🐶" << std::endl;
}

Dog::Dog(const Dog& other)
{
	this->_type = other._type;
	std::cout << "✅ Dog default copy constructor called 🐶" << std::endl;
}

Dog::~Dog(void)
{
	std::cout << "💥 Dog destructor called 🐶" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
		_type = other._type;
	std::cout << "Dog copy assignment operator called 🐶" << std::endl;
	return *this;
}

void Dog::makeSound(void) const
{
	std::cout << "* bark * 🐶" << std::endl;
}
