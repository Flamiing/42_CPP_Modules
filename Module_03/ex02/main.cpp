/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 20:06:05 by alaaouam          #+#    #+#             */
/*   Updated: 2023/07/31 08:07:22 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(void)
{
	FragTrap robot("Wawawiwa");
	FragTrap robotCopy;
	FragTrap robotTest(robot);

	robotCopy = robot;

	robot.highFivesGuys();
	robot.takeDamage(95);
	robot.beRepaired(5);
	robot.takeDamage(10);
	robot.highFivesGuys();
	return 0;
}