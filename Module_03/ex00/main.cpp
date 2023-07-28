/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 20:06:05 by alaaouam          #+#    #+#             */
/*   Updated: 2023/07/27 18:33:05 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap robot("Wawawiwa");
	ClapTrap robotCopy;
	robotCopy = robot;

	size_t count = 0;
	while (count < 9)
	{
		robot.attack("Wall-E");
		count++;
	}
	robot.takeDamage(5);
	robot.beRepaired(5);
	robot.attack("Wall-E");
	robot.takeDamage(20);
	robot.takeDamage(1);

	std::cout << "Copy ClapTrap:" << std::endl;
	robotCopy.setName("Wawawiwa COPY");
	count = 0;
	while (count < 9)
	{
		robotCopy.attack("Wall-E");
		count++;
	}
	robotCopy.takeDamage(5);
	robotCopy.beRepaired(5);
	robotCopy.attack("Wall-E");
	robotCopy.takeDamage(20);
	robotCopy.takeDamage(1);
	return 0;
}