/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 11:41:40 by alaaouam          #+#    #+#             */
/*   Updated: 2023/07/20 12:24:24 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*zombie;
	
	zombie = newZombie("Bababoi");
	zombie->announce();
	randomChump("Wawawiwa");
	delete zombie;
	return (0);
}