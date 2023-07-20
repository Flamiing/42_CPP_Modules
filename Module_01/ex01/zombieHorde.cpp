/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 12:30:25 by alaaouam          #+#    #+#             */
/*   Updated: 2023/07/20 13:12:57 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie	*horde = new Zombie[N];
	int	count = 0;
	
	while (count < N)
	{
		horde[count].setName(name);
		count++;
	}
	return (horde);
}
