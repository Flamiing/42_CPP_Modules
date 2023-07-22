/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 20:06:05 by alaaouam          #+#    #+#             */
/*   Updated: 2023/07/22 01:24:36 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap robot("Wawawiwa");

	size_t count = 0;
	while (count < 48)
	{
		robot.attack("Wall-E");
		count++;
	}
	robot.takeDamage(50);
	robot.beRepaired(50);
	robot.attack("Wall-E");
	robot.takeDamage(200);
	robot.takeDamage(1);
	return 0;
}