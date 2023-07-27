/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:42:27 by alaaouam          #+#    #+#             */
/*   Updated: 2023/07/27 17:12:52 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	if (INFO == 1)
		std::cout << "MateriaSource default constructor called" << std::endl;
	int pos = 0;
	while (pos < 4)
	{
		this->_learned[pos] = NULL;
		pos++;
	}
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	if (INFO == 1)
		std::cout << "MateriaSource copy constructor called" << std::endl;
	int pos = 0;
	while (pos < 0)
	{
		if (other._learned[pos] != NULL)
			this->_learned[pos] = other._learned[pos];
		else
			this->_learned[pos] = NULL;
		pos++;
	}
}

MateriaSource::~MateriaSource(void)
{
	int pos = 0;
	while (pos < 4)
	{
		if (this->_learned[pos] != NULL)
			delete this->_learned[pos];
		pos++;
	}
	if (INFO == 1)
		std::cout << "MateriaSource destructor called" << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	if (INFO == 1)
		std::cout << "MateriaSource  copy assignment operator called" << std::endl;
	if (this != &other)
	{
		int pos = 0;
		while (pos < 0)
		{
			if (this->_learned[pos] != NULL)
				delete this->_learned[pos];
			this->_learned[pos] = other._learned[pos]->clone();
			pos++;
		}
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* learn)
{
	int pos = 0;
	while (pos < 4)
	{
		if (this->_learned[pos] == NULL)
		{
			this->_learned[pos] = learn;
			break ;
		}
		pos++;
	}
	if (pos == 4)
		std::cout << "Cannot learn more materias" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	int pos = 0;
	int typeFound = 0;
	while (pos < 4)
	{
		if (this->_learned[pos] != NULL && this->_learned[pos]->getType() == type)
		{
			typeFound = 1;
			break ;
		}
		pos++;
	}
	if (typeFound == 1)
	{
		if (type == "ice")
			return new Ice();
		else if (type == "cure")
			return new Cure();
	}
	else if (typeFound == 0)
		std::cout << "Cannot create an unknown materia of type " << type << std::endl; 
	return 0;
}
