/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 18:23:48 by alaaouam          #+#    #+#             */
/*   Updated: 2023/07/20 20:39:45 by alaaouam         ###   ########.fr       */
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
		case 4:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break ;
		default:
			std::cout << "[ " << level << " ]" << std::endl;
			while (pos < 4)
			{
				(this->*(functions[pos]))();
				pos++;
			}
			break ;
	}
}
