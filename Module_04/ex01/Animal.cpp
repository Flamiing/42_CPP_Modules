/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 17:42:24 by alaaouam          #+#    #+#             */
/*   Updated: 2023/07/23 15:37:11 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : _type("Animal")
{
	std::cout << "✅ Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal& other) : _type(other._type)
{
	std::cout << "✅ Animal copy constructor called" << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "💥 Animal destructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
	std::cout << "✅ Animal copy assignment operator called" << std::endl;
	if (this != &other)
		this->_type = other._type;
	return *this;
}

void Animal::makeSound(void) const
{
	std::cout << "* random animal sound *" << std::endl;
}

std::string Animal::getType(void) const
{
	return this->_type;
}