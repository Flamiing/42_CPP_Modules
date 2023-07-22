/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 21:06:59 by alaaouam          #+#    #+#             */
/*   Updated: 2023/07/22 01:57:11 by alaaouam         ###   ########.fr       */
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

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->getName() << " is guarding the gate! 🛡️";
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