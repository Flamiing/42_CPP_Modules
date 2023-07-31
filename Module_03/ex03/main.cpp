/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 20:06:05 by alaaouam          #+#    #+#             */
/*   Updated: 2023/07/31 08:09:20 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap robot("Wawawiwa");
	DiamondTrap robotCopy;
	DiamondTrap robotTest(robot);
	
	robotCopy = robot;

	robot.attack("WALL-E");
	robot.whoAmI();
	robot.highFivesGuys();
	robot.guardGate();
	robot.takeDamage(95);
	robot.beRepaired(5);
	robot.takeDamage(10);
	robot.highFivesGuys();
	robot.guardGate();
	return 0;
}