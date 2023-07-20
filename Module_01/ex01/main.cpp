/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 11:41:40 by alaaouam          #+#    #+#             */
/*   Updated: 2023/07/20 13:16:41 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*horde;
	int	numZombies = 10;
	int	count = 0;

	horde = zombieHorde(numZombies, "FallenBrain");
	while (count < numZombies)
	{
		horde[count].announce();
		count++;
	}
	delete[] horde;
	return (0);
}