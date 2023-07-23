/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 12:43:10 by alaaouam          #+#    #+#             */
/*   Updated: 2023/07/23 14:15:44 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	std::cout << "✅ WrongCat default constructor called 🐱" << std::endl;
	this->_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& other)
{
	std::cout << "✅ WrongCat default copy constructor called 🐱" << std::endl;
	this->_type = other._type;
}

WrongCat::~WrongCat(void)
{
	std::cout << "💥 WrongCat destructor called 🐱" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	std::cout << "WrongCat copy assignment operator called 🐱" << std::endl;
	if (this != &other)
		_type = other._type;
	return *this;
}

void WrongCat::makeSound(void) const
{
	std::cout << "* meow * 🐱" << std::endl;
}