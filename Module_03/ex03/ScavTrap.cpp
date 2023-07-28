/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 21:06:59 by alaaouam          #+#    #+#             */
/*   Updated: 2023/07/28 13:55:59 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap default constructor with name called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	if (this != &other)
	{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return *this;
}

void ScavTrap::guardGate(void)
{
	if (this->getHealth() <= 0)
		std::cout << "ScavTrap " << this->getName() << " is dead, he can't guard the gate! 😵" << std::endl;
	else
		std::cout << "ScavTrap " << this->getName() << " is guarding the gate! 🛡️" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->getEnergy() == 0)
		std::cout << "ScavTrap " << this->getName() << " has no energy!" << std::endl;
	else if (this->getHealth() != 0)
	{
		std::cout << "ScavTrap " << this->getName() <<  " attacks "
						   << target << ", causing " << this->getDamage()
						   << " points of damage! 😡" << std::endl;
		this->reduceEnergy();
	}
}