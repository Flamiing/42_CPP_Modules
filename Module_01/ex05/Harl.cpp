/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 18:23:48 by alaaouam          #+#    #+#             */
/*   Updated: 2023/07/20 20:19:55 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
	
}

Harl::~Harl(void)
{
	
}

void	Harl::_debug(void)
{
	std::cout << "I would love to talk about my book..." << std::endl;
}

void	Harl::_info(void)
{
	std::cout << "I came here because you promissed me to talk about my book" << std::endl;
}

void	Harl::_warning(void)
{
	std::cout << "If we don't talk about my book i will leave" << std::endl;
}

void	Harl::_error(void)
{
	std::cout << "AAAAHHHHHHH! I AM LEAVING BECAUSE WE ARE NOT TALKING ABOUT MY BOOK!" << std::endl;
}

void	Harl::complain(std::string level)
{
	int	pos = 0;
	
	std::string	levels[4] =
	{
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	
	void	(Harl::*functions[4])() =
	{
		&Harl::_debug,
		&Harl::_info,
		&Harl::_warning,
		&Harl::_error
	};
	
	while (pos < 4 && levels[pos] != level)
		pos++;
	switch (pos)
	{
		case 0:
			(this->*(functions[0]))();
			break ;
		case 1:
			(this->*(functions[1]))();
			break ;
		case 2:
			(this->*(functions[2]))();
			break ;
		case 3:
			(this->*(functions[3]))();
			break ;
		default:
			std::cout << "Error: There is no level with such a name" << std::endl;
			break ;
	}
}
