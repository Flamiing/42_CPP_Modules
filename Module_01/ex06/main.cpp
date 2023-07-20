/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 18:23:39 by alaaouam          #+#    #+#             */
/*   Updated: 2023/07/20 20:38:09 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	howToUse(void)
{
	std::cerr << "Error: Wrong number of arguments!" << std::endl;
	std::cerr << "Usage: ./harlFilter <level>" << std::endl;
}

int	main(int argc, char **argv)
{
	std::string	level;
	Harl harl;
	
	if (argc != 2)
	{
		howToUse();
		return (1);
	}
	level = std::string(argv[1]);
	harl.complain(level);
	return (0);
}