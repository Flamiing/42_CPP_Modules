/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 13:40:33 by alaaouam          #+#    #+#             */
/*   Updated: 2023/07/23 23:41:53 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string weaponType)
{
	this->_type = weaponType;
}

Weapon::~Weapon(void)
{
	
}

const std::string&	Weapon::getType(void) const
{
	return (this->_type);
}

void	Weapon::setType(std::string new_type)
{
	this->_type = new_type;
}