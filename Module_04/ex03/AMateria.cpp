/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:01:26 by alaaouam          #+#    #+#             */
/*   Updated: 2023/07/26 18:59:44 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void) : _type("none")
{
	if (INFO == 1)
		std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(const std::string type) : _type(type)
{
	if (INFO == 1)
		std::cout << "AMateria default constructor with type called" << std::endl;
}

AMateria::AMateria(const AMateria& other) : _type(other._type)
{
	if (INFO == 1)
		std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria::~AMateria(void)
{
	if (INFO == 1)
		std::cout << "AMateria destructor called" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& other)
{
	if (INFO == 1)
		std::cout << "AMateria copy assignment operator called" << std::endl;
	if (this != &other)
		this->_type = other._type;
	return *this;
}

void AMateria::use(ICharacter& target)
{
	std::cout << "??? " << target.getName() << std::endl;
}

std::string const& AMateria::getType(void) const
{
	return this->_type;
}