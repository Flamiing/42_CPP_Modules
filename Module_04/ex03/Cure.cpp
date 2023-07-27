/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 11:31:49 by alaaouam          #+#    #+#             */
/*   Updated: 2023/07/27 13:58:06 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure")
{
	if (INFO == 1)
		std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(const Cure& other) : AMateria("cure")
{
	if (INFO == 1)
		std::cout << "Cure copy constructor called" << std::endl;
	_type = other._type;
}

Cure::~Cure(void)
{
	if (INFO == 1)
		std::cout << "Cure destructor called" << std::endl;
}

Cure& Cure::operator=(const Cure& other)
{
	if (INFO == 1)
		std::cout << "Cure copy assignment operator called" << std::endl;
	if (this != &other)
		this->_type = other._type;
	return *this;
}

AMateria* Cure::clone(void) const
{
	if (INFO == 1)
		std::cout << "Cure clone function called" << std::endl;
	AMateria* cloneInstance = new Cure();
	return cloneInstance;
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}