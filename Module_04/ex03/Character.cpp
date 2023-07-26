/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:06:59 by alaaouam          #+#    #+#             */
/*   Updated: 2023/07/26 19:27:03 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void) : _name("unknown")
{
	if (INFO == 1)
		std::cout << "Character default constructor called" << std::endl;
	int	pos = 0;
	while (pos < 4)
	{
		this->_inventory[pos] = NULL;
		pos++;
	}
}

Character::Character(const std::string name) : _name(name)
{
	if (INFO == 1)
		std::cout << "Character default constructor with name called" << std::endl;
	int	pos = 0;
	while (pos < 4)
	{
		this->_inventory[pos] = NULL;
		pos++;
	}
}

Character::Character(const Character& other) : _name(other._name)
{
	if (INFO == 1)
		std::cout << "Character copy constructor called" << std::endl;
	int pos = 0;
	while (pos < 4)
	{
		if (other._inventory[pos] != NULL)
			this->_inventory[pos] = other._inventory[pos];
		else
			this->_inventory[pos] = NULL;
		pos++;
	}
}

Character::~Character(void)
{
	if (INFO == 1)
		std::cout << "Character destructor called" << std::endl;
}

Character& Character::operator=(const Character& other)
{
	if (INFO == 1)
		std::cout << "Character assignment operator called" << std::endl;
	if (this != &other)
	{
		int	pos = 0;
	while (pos < 4)
	{
		if (other._inventory[pos] != NULL)
			this->_inventory[pos] = other._inventory[pos]->clone();
		else
			this->_inventory[pos] = NULL;
		pos++;
	}
	}
	return *this;
}

std::string const & Character::getName() const
{
	return this->_name;
}

void Character::equip(AMateria* m)
{
	int pos = 0;
	while (pos < 4)
	{
		if (this->_inventory[pos] == NULL)
		{
			this->_inventory[pos] = m;
			break ;
		}
		pos++;
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx <= 3)
		this->_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx <= 3)
		if (this->_inventory[idx] != NULL)
			this->_inventory[idx]->use(target);
}