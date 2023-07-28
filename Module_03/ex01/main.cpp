/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 20:06:05 by alaaouam          #+#    #+#             */
/*   Updated: 2023/07/28 14:02:47 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap robot("Wawawiwa");
	ScavTrap robotCopy;
	robotCopy = robot;

	size_t count = 0;
	while (count < 48)
	{
		robot.attack("Wall-E");
		count++;
	}
	robot.takeDamage(50);
	robot.beRepaired(50);
	robot.attack("Wall-E");
	robot.guardGate();
	robot.takeDamage(200);
	robot.takeDamage(1);

	std::cout << "Copy ScavTrap:" << std::endl;

	count = 0;
	while (count < 48)
	{
		robotCopy.attack("Monster");
		count++;
	}
	robotCopy.takeDamage(50);
	robotCopy.beRepaired(50);
	robotCopy.attack("Monster");
	robotCopy.guardGate();
	robotCopy.takeDamage(200);
	robotCopy.takeDamage(1);
	return 0;
}