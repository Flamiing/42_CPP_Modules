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
	this->_type = "WrongCat";
	std::cout << "✅ WrongCat default constructor called 🐱" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other)
{
	this->_type = other._type;
	std::cout << "✅ WrongCat default copy constructor called 🐱" << std::endl;
}

WrongCat::~WrongCat(void)
{
	std::cout << "💥 WrongCat destructor called 🐱" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	if (this != &other)
		_type = other._type;
	std::cout << "WrongCat copy assignment operator called 🐱" << std::endl;
	return *this;
}

void WrongCat::makeSound(void) const
{
	std::cout << "* meow * 🐱" << std::endl;
}