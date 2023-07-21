/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 20:07:05 by alaaouam          #+#    #+#             */
/*   Updated: 2023/07/21 21:03:23 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : _name(other._name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints),  _attackDamage(other._attackDamage)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	if (this != &other)
	{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->getEnergy() == 0)
		std::cout << "ClapTrap " << this->getName() << " has no energy!" << std::endl;
	else if (this->getHealth() != 0)
	{
		std::cout << "ClapTrap " << this->getName() <<  " attacks "
						   << target << ", causing " << this->getDamage()
						   << " points of damage! 😡" << std::endl;
		this->_energyPoints--;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->getHealth() <= 0)
		std::cout << "ClapTrap " << this->getName() << " is already dead! 😵" << std::endl;
	else if (this->getHealth() != 0)
	{
		std::cout << "ClapTrap " << this->getName() <<  " got attacked causing "
						   << amount << " points of damage! 😢" << std::endl;
		this->_hitPoints -= amount;
		if (this->getHealth() <= 0)
			std::cout << "ClapTrap " << this->getName() << " died! 😵" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->getEnergy() == 0)
		std::cout << "ClapTrap " << this->getName() << " has no energy!" << std::endl;
	else if (this->getHealth() > 0)
	{
		std::cout << "ClapTrap " << this->getName() <<  " repairs itself and recovers "
						   << amount << "HP back! 😊" << std::endl;
		this->_energyPoints--;
		this->_hitPoints += amount;
	}
}

std::string ClapTrap::getName(void) const
{
	return this->_name;
}

int ClapTrap::getHealth(void) const
{
	return this->_hitPoints;
}

int ClapTrap::getEnergy(void) const
{
	return this->_energyPoints;
}

int ClapTrap::getDamage(void) const
{
	return this->_attackDamage;
}